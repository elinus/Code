#include <iostream>
#include <string>

using namespace std;

class Animal {
    protected:
        string mName;
    public:
        Animal(string name) : mName(name) {};
        virtual const char* speak() = 0;
};

const char* Animal::speak() {
    return "buzz";
}

class Cow : public Animal {
    public:
        Cow(string name) : Animal(name) {};
        const char* speak() {
            return Animal::speak();
        }

};

int main (int argc, char const *argv[])
{
    //error: variable type 'Animal' is an abstract class
    //Animal anim_obj;
    Cow cooo("Cooo");
    cout << cooo.speak() << endl;
    return 0;
}

