#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


class Shape
{

};

// Shape - Rectangle : is-a 관계
class Rectangle : public Shape
{

};

// deque 구현이 맞습니다. 강의에 나온 부분은 잘못 됐습니다
// Queue - deque : has-a 관계
class Queue0
{
private:
    deque<int> v;
public:
    void push(int value)
    {
        v.push_back(value);
    }

    void pop()
    {
        v.pop_front();
    }

    int top()
    {
        return v.front();
    }
};


// public 상속은 deque의 모든 인터페이스를 public으로 상속한다.
// private 상속은 deque의 모든 인터페이스를 private으로 상속한다.
// 따라서 Queue1에서는 deque의 인터페시를 사용할 수 있지만 외부에서는 사용할 수 없다
// 왠만하면 사용하지 말자.
// deque의 protected 멤버 함수를 사용하고 싶은 경우 사용하면 좋다
// 지정자를 생략하면 private 상속(struct의 경우는 public)

class Queue1 : private deque<int>
{
public:
    void push(int value)
    {
        push_back(value);
    }

    void pop()
    {
        pop_front();
    }

    int top()
    {
        return front();
    }
};


// deque의 인터페이스를 Queue2의 자식에게까지 공개하기 위해 protected 상속을 한다
class Queue2 : protected deque<int>
{
public:
    virtual void push(int value)
    {
        push_back(value);
    }

    virtual void pop()
    {
        pop_front();
    }

    virtual int top()
    {
        return front();
    }

    virtual ~Queue2()
    {

    }
};


class PriorityQueue : public Queue2
{
public:
    virtual void push(int value) override
    {
        Queue2::push(value);
        push_heap(begin(), end());
    }

    virtual void pop() override
    {
        pop_heap(begin(), end());
        Queue2::pop_back();
    }

    virtual int top() override
    {
        return front();
    }
};



int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(100);
    pq.push(0);


    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();
}