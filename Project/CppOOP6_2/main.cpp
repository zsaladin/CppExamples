#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// 강의에 Queue라고 나온 부분은 잘못 됐습니다.
// 실제로 Stack을 구현하고 있습니다
template<typename T, int N>
class Stack
{
private:
    size_t _size;
    T _items[N];

    // vector에 T를 전달하면 됨
    //std::vector<T> _items;



public:
    Stack();
    void push(T item);
    void pop();
    T& top();
};

template<typename T, int N>
Stack<T, N>::Stack()
    : _size(0)
    , _items{}
{

}

template<typename T, int N>
void Stack<T, N>::push(T item)
{
    if (_size < N)
    {
        _items[_size++] = item;
    }
    else
    {
        throw std::out_of_range("overflow");
    }
}

template<typename T, int N>
void Stack<T, N>::pop()
{
    if (_size == 0)
    {
        throw std::out_of_range("underflow");
    }
    --_size;
}


template<typename T, int N>
T& Stack<T, N>::top()
{
    if (_size == 0)
    {
        throw std::out_of_range("underflow");
    }
    return _items[_size - 1];
}

int main()
{
    Stack<int, 3> s0;
    s0.push(1);
    s0.push(2);
    s0.push(4);

    cout << s0.top() << endl;
    s0.pop();

    cout << s0.top() << endl;


    Stack<std::string, 10> s1;
    s1.push("abcd");
    s1.push("1234");
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();

    try
    {
        s1.pop();
    }
    catch (std::out_of_range& e)
    {
        cout << e.what() << endl;
    }
}