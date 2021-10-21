import std.core;
import std.memory;
import std.threading;

int main()
{
    // module은 include 의 많은 단점들을 보완함
    // - 매번 헤더를 소스 파일에 복사/붙여넣기 하는 것
    // - pragam, ifndef 등을 사용하지 않게 됨
    // - 헤더 내부에서 의도하지 않은 것들에 대한 공개

    std::cout << "a" << std::endl;

    std::vector<int> nums{ 1, 2, 3 };
    for (auto num : nums)
    {
        std::cout << num << std::endl;
    }

    std::thread th([] {
        std::cout << "async" << std::endl;
        });

    std::unique_ptr<int> i = std::make_unique<int>(10);
    std::cout << *i << std::endl;
    th.join();
}