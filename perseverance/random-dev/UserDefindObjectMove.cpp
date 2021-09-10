#include <iostream>
#include <memory>
#include <string>

struct Person
{
    int id;
    std::string name;
    Person(int id, std::string name) : id(id), name(name) {
        std::cout << "Person ctor :: " << this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &out, const Person &p) {
        out << "[obj = " << &p << "] id = " << p.id << ", name = " << p.name << "\n";
        return out;
    }
};

void swap(Person &p1, Person &p2) {
    Person tmp = std::move(p1);
    p1 = std::move(p2);
    p2 = std::move(tmp);
}

int main() {
    Person p1(0, "P1");
    std::cout << p1;
    Person p2(1, "P2");
    std::cout << p2;

    swap(p1, p2);
    std::cout << "After swap!" << std::endl;
    std::cout << p1;
    std::cout << p2;
    return 0;
}
