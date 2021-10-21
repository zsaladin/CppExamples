#include <iostream>
#include <type_traits>

template<typename T>
concept NonPointer = !std::is_pointer<T>::value;  // concept 을 이용하면 template 에 대한 제약을 쉽게 걸 수 있다


// 다양한 방식의 concept 적용
template<NonPointer T>
void swap0(T& x, T& y)
{
}

template<typename T> requires NonPointer<T>
void swap1(T& x, T& y)
{
}

template<typename T>
void swap2(T& x, T& y) requires NonPointer<T>
{
}


template<typename T>
struct is_scoped_enum
{
    static const bool value = std::is_enum_v<T> && !std::is_convertible_v<T, int>;
};

template<typename T>
concept ScopedEnum = is_scoped_enum<T>::value;

template<ScopedEnum T> // enable_if 를 사용하지 않고 매우 쉽게 제약
std::ostream& operator<<(std::ostream& os, const T& t)
{
    return (std::cout << static_cast<std::underlying_type_t<T>>(t));
}

enum class Type
{
    A, B
};

// 다양한 concept 활용법
template<typename T>
concept HasNum = requires
{
    T::num;
};

template<typename T>
concept HasType = requires
{
    typename T::type;
};

template<typename T>
concept HasNumAndType = HasNum<T> && HasType<T>;


template<typename T>
concept HasNumOrType = HasNum<T> || HasType<T>;

template<typename T, typename S>
concept Addable = requires(T t, S s)
{
    t + s;
}
&& std::is_integral_v<T>
&& std::is_integral_v<S>;


int main()
{
    int x = 10, y = 20;
    swap0(x, y);

    int* px = &x;
    int* py = &y;

    // 제약이 걸려 컴파일 되지 않음
    //swap0(px, py);
    //swap1(px, py);

    std::cout << Type::A;
}