#include <iostream>

using std::cout;
using std::endl;


enum Unscoped
{
    A, B
};


enum class Scoped : long long
{
    A, B = 10000000000
};


template<typename T>
struct is_scoped_enum
{
    // enum 인데 int로 변환이 되지 않으면 Scoped
    static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
};

// SFINAE(Substitution failure is not an erro) 이용
template<typename T, typename std::enable_if<is_scoped_enum<T>::value, int>::type = 0>
std::ostream& operator<<(std::ostream& os, const T& value)
{
    // underlying_type  을 통해 타입을 알아냄
    using t = typename std::underlying_type<T>::type;
    cout << static_cast<t>(value);
    return os;
}

int main()
{
    cout << std::boolalpha;

    cout << A << endl;
    cout << static_cast<int>(Scoped::B) << endl; // overflow

    cout << static_cast<std::underlying_type<Scoped>::type>(Scoped::B) << endl;
    cout << Scoped::A << endl;
    cout << Unscoped::B << endl;
}