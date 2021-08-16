#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship { parent, child, sibling };

struct Person {
    string m_name;
};

struct Relationships { // Low-level
    vector<tuple<Person, Relationship, Person>> m_relations;
    void add_parent_and_child(const Person& parent, const Person& child) {
        m_relations.push_back({ parent, Relationship::parent, child });
        m_relations.push_back({ child, Relationship::child, parent });
    }
};

struct Research {
    Research(const Relationships& relationships) {
        auto& relations = relationships.m_relations;
        for (auto &&[first, rel, second] : relations) {
            if (first.m_name == "John" && rel == Relationship::parent) {
                cout << "John has a child called " << second.m_name << endl;
            }
        }
    }
};

//main_20210201_1259
int main() {
    Person parent{ "John" };
    Person child1{ "Chris" };
    Person child2{ "Matt" };

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
    return 0;
}
