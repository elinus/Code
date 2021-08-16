#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum class Relationship { parent, child, sibling };

struct Person {
  string name;
};

struct RelationshipBrowser {
  virtual vector<Person> find_all_child_of(const string &name) const = 0;
};

struct Relationships : RelationshipBrowser {
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person &parent, const Person &child) {
    auto r1 = make_tuple(parent, Relationship::parent, child);
    auto r2 = make_tuple(child, Relationship::child, parent);
    relations.push_back(r1);
    relations.push_back(r2);
  }

  vector<Person> find_all_child_of(const string &name) const override {
    vector<Person> result;
    for (auto &tup : relations) {
      if (get<0>(tup).name == "John" && get<1>(tup) == Relationship::parent)
        result.push_back(get<2>(tup));
    }
    return result;
  }
};

struct Research {
  //   Research(const Relationships &relationships) {
  //     for (auto &tup : relationships.relations) {
  //       if (get<0>(tup).name == "John" && get<1>(tup) ==
  //       Relationship::parent)
  //         cout << "John has a child called " << get<2>(tup).name << endl;
  //     }
  //   }
  Research(const RelationshipBrowser &rb) {
    for (auto &child : rb.find_all_child_of("John")) {
      cout << "John has a child called " << child.name << endl;
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
