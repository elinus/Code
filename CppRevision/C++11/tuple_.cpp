#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, double, std::string> foo()
{
    std::tuple<int, double, std::string> result(14, 20.03, "aks");
    return result;
}

int main (int argc, char *argv[])
{
    std::tuple<int, double, std::string> value = foo();
    int ii = std::get<0>(value);
    double dd = std::get<1>(value);
    std::string ss = std::get<2>(value);
    std::cout << ii << " " << dd << " " << ss << std::endl;
    
    //int i4 = std::get<4>(value); // error: static assertion failed: tuple index is in range
    int i = 0;
    //int iii = std::get<i>(value); // error: the value of ‘i’ is not usable in a constant expression
    
    const int j = 0;
    int jjj = std::get<j>(value);

    std::tuple<std::string, int> person1{"elinus", 30};
    std::cout << std::get<0>(person1) << std::endl;

    auto person2 = std::make_tuple("aks, 28");
    return 0;
}

