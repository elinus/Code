#include <iostream>
#include <set>
#include <iterator>
#include <string>

class Person {
    friend std::ostream & operator << (std::ostream &, const Person &);
    private:
        int age;
        std::string name;
    public:
        Person(std::string name, int age): name(name), age(age) {}
        ~Person(){};
        bool operator<(const Person & other) const {
            return this->age < other.age || this->name.size() < other.name.size();
        }
};

std::ostream & operator << (std::ostream & out, const Person & person) {
    out << person.age << " " << person.name << "\n";
    return out;
}

int main (int argc, char *argv[]) {
    std::set<Person> ps;
    Person p1("sunil", 32), p2("elinus", 23);
    
    ps.insert(p1);
    ps.insert(p2);

    for (auto it = ps.begin(); it != ps.end(); ++it) {
        std::cout << *it;
    }
    return 0;
}

