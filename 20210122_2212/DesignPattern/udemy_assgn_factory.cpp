#include <iostream>
#include <string>

using namespace std;

struct Person {
  int id;
  string name;
};

class PersonFactory {
public:
  static int id;
  Person create_person(const string &name) {
    Person pers_;
    pers_.id = id++;
    pers_.name = name;
    return pers_;
  }
};

int PersonFactory::id = 0;

int main(int argc, char const *argv[]) {
  PersonFactory pf;
  Person p1 = pf.create_person("p1");
  cout << p1.id << " " << p1.name << "\n";
  Person p2 = pf.create_person("p2");
  cout << p2.id << " " << p2.name << "\n";
  return 0;
}
