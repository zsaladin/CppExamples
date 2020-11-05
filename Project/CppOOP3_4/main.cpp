#include <iostream>

using namespace std;


// 추상 클래스
// 순수 가상함수만 존재하기 때문에 인터페이스라고 볼 수 있음
class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};


class Circle : public Shape
{
private:
    double _radius;

public:
    Circle(double radius)
        : _radius(radius)
    {

    }

    virtual double getArea() const override
    {
        return _radius * _radius * 3.14;
    }
};


class Rectangle : public Shape
{
private:
    double _width;
    double _height;

public:
    Rectangle(double width, double height)
        : _width(width), _height(height)
    {

    }

    virtual double getArea() const override
    {
        return _width * _height;
    }
};



class AreaAverage
{
private:
    double _total = 0;
    int _size = 0;

public:
    double operator()(Shape& shape)
    {
        _size += 1;
        _total += shape.getArea();
        return _total / _size;
    }
};

int main()
{
    //Shape s;  // 추상 클래스는 생성할 수 없다
    Circle c(10);
    cout << c.getArea() << endl;

    Rectangle r(10, 20);
    cout << r.getArea() << endl;

    // 추상 클래스는 생성할 수 없지만 가리킬 수는 있다.
    Shape* s0 = &c;
    Shape& s1 = r;

    cout << s0->getArea() << endl;
    cout << s1.getArea() << endl;


    AreaAverage aavg;
    cout << aavg(c) << endl;
    cout << aavg(r) << endl;
}
