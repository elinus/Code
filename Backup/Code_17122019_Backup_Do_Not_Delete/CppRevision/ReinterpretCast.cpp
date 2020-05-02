#include <iostream>

using namespace std;

class Mango {
    public:
        void eatMango() {
            std::cout << "Eating Mango!\n";
        }
};

class Orange {
    public:
        void eatOrange() {
            std::cout << "Eating Orange!\n";
        }
};

struct myStruct {
    int x;
    int y;
    char c;
    bool b;
};

int main(int argc, char const *argv[]) {
    Mango *mp = new Mango();
    Orange *op = new Orange();
    Mango *new_mp = reinterpret_cast<Mango *>(op);
    new_mp->eatMango();

    myStruct mys;
    mys.x = 14;
    mys.y = 20;
    mys.c = 's';
    mys.b = true;
    int *p = reinterpret_cast<int *>(&mys);
    std::cout << *p << "\n";
    p++;
    std::cout << *p << "\n";
    p++;
    char *c = reinterpret_cast<char *>(p);
    std::cout << *c << "\n";
    std::cout << *reinterpret_cast<bool *>(++c) << "\n";
    return 0;
}

