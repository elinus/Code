#include <iostream>
#include <future>

int do_something(char ch) {
    std::cout << "char = " << ch << ", value = " << static_cast<int>(ch) << std::endl;
    return ch;
}

int func1() {
    return do_something('.');
}

int func2() {
    return do_something('+');
}

int main(int argc, char const *argv[])
{
    std::future<int> res1(std::async(func1));
    int res2 = func2();
    int result = res2 + res1.get();
    std::cout << "result = " << result << std::endl;
    return 0;
}
