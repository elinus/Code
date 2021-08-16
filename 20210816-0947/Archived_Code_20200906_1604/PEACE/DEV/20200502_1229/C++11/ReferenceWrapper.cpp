#include <iostream>
#include <string>
#include <functional>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string tom { "Tom" }, berta { "Berta" };
    std::vector<std::reference_wrapper<std::string>> names { tom, berta };
    std::string jim { "Jim" };
    names.push_back(jim);
    for (auto name : names) {
        name.get() += " Beam";
    }
    std::cout << jim << std::endl;
    return 0;
}
