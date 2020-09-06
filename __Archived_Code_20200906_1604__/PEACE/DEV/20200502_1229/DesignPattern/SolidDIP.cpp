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
  virtual vector<Person> find_all_children_of(const string &name) = 0;
};

struct Relationships : RelationshipBrowser {
  vector<tuple<Person, Relationship, Person>> relations;
  void add_parent_and_child(const Person &person, const Person &child) {
    relations.push_back({person, Relationship::parent, child});
    relations.push_back({child, Relationship::child, person});
  }
  vector<Person> find_all_children_of(const string &name) override {
    vector<Person> result;
    for (auto && [first, rel, second] : relations) {
      if (first.name == name && rel == Relationship::parent) {
        result.push_back(second);
      }
    }
    return result;
  }
};

struct Research {
  Research(RelationshipBrowser &browser) {
    for (auto &child : browser.find_all_children_of("John")) {
      cout << "John has a child called " << child.name << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  Person parent{"John"}, child1{"Chris"}, child2{"Matt"};
  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);
  Research res_(relationships);
  return 0;
}
