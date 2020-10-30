#include <iostream>
#include <chrono>


using namespace std;


class Length
{
private:
    const long double _value;
    Length(long double value) : _value(value)
    {

    }

    friend Length operator"" _m(unsigned long long value);
    friend Length operator"" _m(long double value);
    friend Length operator"" _km(unsigned long long value);
    friend Length operator"" _km(long double value);
    friend Length operator"" _mm(unsigned long long value);
    friend Length operator"" _mm(long double value);
    friend Length operator"" _cm(unsigned long long value);
    friend Length operator"" _cm(long double value);

public:
    long double m() const { return _value; }
    long double km() const { return _value * 0.001; }
    long double mm() const { return _value * 1000; }
    long double cm() const { return _value * 100; }

    Length operator+() const
    {
        return Length(_value);
    }

    Length operator-() const
    {
        return Length(-_value);
    }

    Length operator+(const Length& length) const
    {
        return Length(_value + length._value);
    }

    Length operator-(const Length& length) const
    {
        return Length(_value - length._value);
    }
};

Length operator"" _m(unsigned long long value)
{
    return Length(value);
}

Length operator"" _m(long double value)
{
    return Length(value);
}

Length operator"" _km(unsigned long long value)
{
    return Length(value * 1000L);
}

Length operator"" _km(long double value)
{
    return Length(value * 1000L);
}

Length operator"" _mm(unsigned long long value)
{
    return Length(value * 0.001L);
}

Length operator"" _mm(long double value)
{
    return Length(value * 0.001L);
}

Length operator"" _cm(unsigned long long value)
{
    return Length(value * 0.01L);
}

Length operator"" _cm(long double value)
{
    return Length(value * 0.01L);
}

int main()
{
    // 표준 라이브러리에서 사용하는 사용자 정의 리터럴
    chrono::minutes m = 24h + 5min;
    cout << m.count() << endl;

    Length len = 1_m + 1_km + 1_cm + 1_mm;
    cout.precision(16);
    cout << len.m() << endl;
    cout << len.km() << endl;
    cout << len.cm() << endl;
    cout << len.mm() << endl;
}