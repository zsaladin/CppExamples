#include <iostream>

using namespace std;


// �߻� Ŭ����
// ���� �����Լ��� �����ϱ� ������ �������̽���� �� �� ����
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
    //Shape s;  // �߻� Ŭ������ ������ �� ����
    Circle c(10);
    cout << c.getArea() << endl;

    Rectangle r(10, 20);
    cout << r.getArea() << endl;

    // �߻� Ŭ������ ������ �� ������ ����ų ���� �ִ�.
    Shape* s0 = &c;
    Shape& s1 = r;

    cout << s0->getArea() << endl;
    cout << s1.getArea() << endl;


    AreaAverage aavg;
    cout << aavg(c) << endl;
    cout << aavg(r) << endl;
}