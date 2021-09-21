#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <queue>

using namespace std::chrono_literals;

struct Test
{
    int num;
    Test(int num) : num(num)
    {
        std::cout << "Construct : " << num << std::endl;
    }

    ~Test()
    {
        std::cout << "Destruct : " << num << std::endl;
    }
};
thread_local Test test(10);  // thread 개수 만큼 생성 됨

void loop0()
{
    for (int i = 0; i < 10; ++i)
    {
        thread_local int num = 10;  // thread 마다 한 번 초기화 됨, static은 thread 와 관계 없이 한 번 초기화
        num++;
        std::cout << num << std::endl;
    }
}


int num = 0;
void loop1()
{
    for (int i = 0; i < 1000000; ++i)
    {
        num++;
    }

}

void longTimeJob()
{
    std::this_thread::sleep_for(200ms);
}

void produce(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
    while (true)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lock(m);
            jobQueue.push(1);
            std::cout << "produce : " << jobQueue.size() << std::endl;
        }
        cv.notify_one();
    }
}

void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(m);
            if (jobQueue.empty())  // lost wakeup
            {
                cv.wait(lock);
            }

            if (jobQueue.empty())  // spurious wakeup
            {
                continue;
            }

            int result = jobQueue.front();
            jobQueue.pop();

            std::cout << "consume : " << jobQueue.size() << std::endl;
        }
        longTimeJob();
    }
}



int main()
{
    {
        // thread 기본적인 사용법
        std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;

        // callable 인자
        std::thread th([] {
            std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(1s);
            });
        th.join();

        std::cout << "Complete" << std::endl;
    }
    {
        // thread local 사용
        std::thread th(loop0);
        loop0();
        th.join();
    }
    {
        std::thread th(loop1);
        loop1();
        th.join();

        std::cout << num << std::endl; // 항상 2000000 이 나오지 않는다

        // num += 1 연산
        // 1. load num to register
        // 2. register += 1
        // 3. store register to num

        // 아래와 같은 상황이 발생할 수 있음
        // thread0     thread1
        // 1. load(0)
        //             1. load(0)
        // 2. reg(1)   2. reg(1)
        // 3. store(1) 3. store(1)
    }
    {
        // lock

        std::mutex m;
        int num = 0;
        auto func = [&num, &m]
        {
            for (int i = 0; i < 1000000; ++i)
            {
                // 임계 영역 설정
                m.lock();
                num++;
                m.unlock(); // 임계 영역에서 예외 발생 시 실행되지 않음, std::lock_guard 를 이용하여 해제를 보장
            }
        };

        std::thread th0(func);
        std::thread th1(func);

        th0.join();
        th1.join();
        std::cout << num << std::endl;  // 2000000
    }
    {
        // atomic
        // lock 이 없어도 됨
        std::atomic_int num = 0;
        auto func = [&num]
        {
            for (int i = 0; i < 1000000; ++i)
            {
                num++;
            }
        };

        std::thread th0(func);
        std::thread th1(func);

        th0.join();
        th1.join();
        std::cout << num << std::endl;  // 2000000
    }
    {
        // producer, consumer
        std::mutex m;
        std::condition_variable cv;
        std::queue<int> jobQueue;
        std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer0(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer1(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));

        producer.join();
        consumer0.join();
        consumer1.join();
    }
}