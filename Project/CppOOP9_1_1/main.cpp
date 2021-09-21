#include <iostream>
#include <map>

template<auto N0, auto N1> // C++17부터
auto add()
{
    return N0 + N1;
}

template<auto... Args>
auto sum()
{
    return (Args + ...); // C++17부터
    // Args + ... : (A[0] + (A[1] + (A[2] + ... (A[n - 1] + A[n])
    // ... + Args : (A[0] + A[1]) + A[2]) + A[3]) + ... A[n])
    // Args + ... + B : (A[0] + (A[1] + (A[2] + ... (A[n - 1] + (A[n] + B)
    // B + ... + Args : (B + A[0]) + A[1]) + A[2]) + A[3]) + ... A[n])
}


class Person
{
public:
    float weight;
    float height;
    
    void func() {}
};

int main()
{
    std::cout << add<10, 2>() << std::endl;
    std::cout << add<10, 200000000000>() << std::endl;

    std::cout << sum<1, 2, 3>() << std::endl;
    std::cout << sum<10000000000000, 200000000000000, 3000000000000000>() << std::endl;

    std::map<int, std::string> m{
        {1, "1"}
    };

    {
        // structured binding
        const auto& [key, value] = *m.begin();
        std::cout << key << std::endl;
        std::cout << value << std::endl;

        int nums[]{ 1, 2, 3 };
        auto [x, y, z] = nums;

        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;

        nums[0] = 0;

        std::cout << x << std::endl;


        std::tuple<int, float, std::string> t0{ 1, 2.0f, "3" };
        auto t1 = std::make_tuple(1, 2.0f, "3"); // 간결

        int x0;
        float y0;
        std::string z0;
        std::tie(x0, y0, z0); // 장황하고 불편...

        auto [x1, y1, z1] = t1; // 편함

        Person p{ 64.f, 172.f };
        auto [weight, height] = p; // 간결
    }
}