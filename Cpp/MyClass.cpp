#include <iostream>
#include <vector>

class MyClass {
    private:
        static std::vector<char> sMyChars;
    public:
        class _init {
            public:
                _init() {
                    sMyChars.push_back('a');
                    sMyChars.push_back('e');
                    sMyChars.push_back('i');
                    sMyChars.push_back('o');
                    sMyChars.push_back('u');
                }
        };
    private:
        static _init sInitializer;
};

std::vector<char> MyClass::sMyChars;
MyClass::_init MyClass::sInitializer;

int main (int argc, char *argv[]) {
    
    return 0;
}

