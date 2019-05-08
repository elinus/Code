#include <iostream>
#include <string>

using namespace std;

class Base {
    protected:
        int mValue;
    public:
        Base(int value) : mValue(value) {}
        virtual const char* getName() { return "Base"; }
        int getValue() { return mValue; }
};

class Derived : public Base {
    public:
        Derived(int value) : Base(value) {}
        virtual const char* getName() { return "Derived"; }
        int getValueDouble() { return mValue * 2; }
};

class Animal {
    protected:
        string mName;
    public:
        Animal(string name) : mName(name) {};
        string getName() { return mName; }
        virtual const char* speak() { return "???"; }
};

class Cat : public Animal {
    public:
        Cat(string name): Animal(name) {}
        virtual const char* speak() { return "Meow"; }
};

class Dog : public Animal {
    public:
        Dog(string name): Animal(name) {}
        virtual const char* speak() { return "Woof"; }
};

class Cow : public Animal {
    public:
        Cow(string name): Animal(name) {}
        virtual const char* speak() { return "Moo"; }
};

void print_anim(Animal &anim) {
    cout << "animal name = " << anim.getName() << ", sound = " << anim.speak() << endl;
}

int main (int argc, char const *argv[])
{
    Derived derived(14);
    cout << "derived(" << &derived << ") name = " << derived.getName() << ", value = " << derived.getValue() << endl;
    Derived &rDerived = derived;
    cout << "derived(" << &rDerived << ") name = " << rDerived.getName() << ", value = " << rDerived.getValue() << endl;
    Derived *pDerived = &derived;
    cout << "derived(" << pDerived << ") name = " << pDerived->getName() << ", value = " << pDerived->getValue() << endl;
    
    Base *pBase = &derived;
    cout << "pBase(" << pBase << ") name = " << pBase->getName() << ", value = " << pBase->getValue() << endl;
    Base &rBase = derived;
    cout << "rBase(" << &rBase << ") name = " << rBase.getName() << ", value = " << rBase.getValue() << endl;
   
    //error: no member named 'getValueDouble' in 'Base'
    //rBase.getValueDouble(); 
    
    Cat cat("Fred");
    cout << "cat name = " << cat.getName() << ", sound = " << cat.speak() << endl;
    Dog dog("Gabro");
    cout << "dog name = " << dog.getName() << ", sound = " << dog.speak() << endl;
    Cow cow("Coo");
    Animal *anim_cow = &cow;
    cout << "anim name = " << anim_cow->getName() << ", sound = " << anim_cow->speak() << endl;
    print_anim(cat);

    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog gabro("Gabro"), pooky("Pooky"), truffle("Truffle");
    Animal *animals[] = {&fred, &gabro, &misty, &pooky, &zeke, &truffle};
    for (int i = 0; i < 6; i++) {
        cout << "animals name = " << animals[i]->getName() << ", sound = " << animals[i]->speak() << endl;
    }

    return 0;
}

