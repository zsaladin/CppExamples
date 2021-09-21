#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    {
        // promise - future - value
        std::promise<int> pro;
        std::future<int> fut = pro.get_future();

        std::thread th([](std::promise<int> pro) {
            std::this_thread::sleep_for(2s);
            pro.set_value(10);
            }, std::move(pro));

        std::cout << fut.get() << std::endl; // 10
        th.join();
    }
    {
        // promise - future - exception
        std::promise<int> pro;
        std::future<int> fut = pro.get_future();

        std::thread th([](std::promise<int> pro) {
            try {
                throw std::runtime_error("err");
            }
            catch (...) {
                std::exception_ptr e = std::current_exception();
                pro.set_exception(e);
            }
            }, std::move(pro));

        try 
        {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err)
        {
            std::cout << err.what() << std::endl;
        }
        th.join();
    }
    {
        // packaged_task
        std::packaged_task<int(int)> task([](int value) {
            if (value < 0)
                throw std::runtime_error("err");
            return value;
            });

        std::future<int> fut = task.get_future();
        std::thread th(std::move(task), 10);
        try {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
        }
        th.join();
    }
    {
        // async
        std::future<int> fut = std::async([](int value) {
            if (value < 0)
                throw std::runtime_error("errr");
            return value;
            }, -1);
        try {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
        }
    }
}