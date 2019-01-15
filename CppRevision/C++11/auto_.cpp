#include <iostream>
#include <map>
#include <string>

int main (int argc, char *argv[])
{
    std::map<std::string, std::map<std::string, int> > ng;
    ng["A"]["B"] = 1;
    ng["A"]["C"] = 1;
    ng["B"]["C"] = 1;
    for (auto it1 = ng.begin(); it1 != ng.end(); ++it1) {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
            std::cout << it1->first << " " << it2->first << " " << it2->second << std::endl;
        }
    }
    
    // errors
    auto x = 1;
    //x = "dummy"; // error: invalid conversion from ‘const char*’ to ‘int’ [-fpermissive]
    //auto y; // error: declaration of ‘auto y’ has no initializer
    
    return 0;
}

