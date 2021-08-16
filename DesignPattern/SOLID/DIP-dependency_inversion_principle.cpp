#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum class Relationship { parent, child, sibling };

struct Person {
  string name;
};

struct Relationships {
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person &parent, const Person &child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }
};

struct Research {
  Research(const Relationships &relationships) {
    for (auto &tup : relationships.relations) {
      if (get<0>(tup).name == "John" && get<1>(tup) == Relationship::parent)
        cout << "John has a child called " << get<2>(tup).name << endl;
    }
  }
};

int main(int argc, char const *argv[]) {
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};
  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);
  Research _(relationships);
  return 0;
}
