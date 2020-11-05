#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Shape
{

};

// Shape - Rectangle : is-a 관계
class Rectangle : public Shape
{

};


// Queue - vector : has-a 관계
class Queue0
{
private:
    vector<int> v;
public:
    void push(int value)
    {
        v.push_back(value);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }
};


// public 상속은 vector의 모든 인터페이스를 public으로 상속한다.
// private 상속은 vector의 모든 인터페이스를 private으로 상속한다.
// 따라서 Queue1에서는 vector의 인터페시를 사용할 수 있지만 외부에서는 사용할 수 없다
// 왠만하면 사용하지 말자.
// vector의 protected 멤버 함수를 사용하고 싶은 경우 사용하면 좋다
// 지정자를 생략하면 private 상속(struct의 경우는 public)

class Queue1 : private vector<int>
{
public:
    void push(int value)
    {
        push_back(value);
    }

    void pop()
    {
        pop_back();
    }

    int top()
    {
        return back();
    }
};


// vector의 인터페이스를 Queue2의 자식에게까지 공개하기 위해 protected 상속을 한다
class Queue2 : protected vector<int>
{
public:
    virtual void push(int value)
    {
        push_back(value);
    }

    virtual void pop()
    {
        pop_back();
    }

    virtual int top()
    {
        return back();
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