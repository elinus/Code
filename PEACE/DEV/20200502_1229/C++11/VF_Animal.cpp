#include <iostream>
#include <string>
#include <string_view>

class Animal {
    private:
    std::string m_Name;
    public:
    Animal(const std::string & name)
        : m_Name { name }
    {}
    const std::string & getName() const {
        return m_Name;
    }
    virtual std::string_view speak() const {
        return "???";
    }
};

class Cat : public Animal {
    public:
    Cat(const std::string & name)
        : Animal { name }
    {}
    virtual std::string_view speak() const {
        return "Meow";
    }
};

class Dog : public Animal {
    public:
    Dog(const std::string & name)
        : Animal { name }
    {}
    virtual std::string_view speak() const {
        return "Woof";
    }
};

int main(int argc, char const *argv[])
{
    Cat cat { "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';
 
    Dog dog { "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';
 
    Animal *pAnimal { &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
 
    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    std::cout << "\n\n";
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
 
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };
 
    Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (const auto animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    return 0;
}
