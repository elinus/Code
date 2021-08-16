#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship { parent, child, sibling };

struct Person {
	string m_name;
};

struct RelationshipBrowser {
	virtual vector<Person> find_all_children_of(const string& name) = 0;
};


struct Relationships : RelationshipBrowser { // Low-level
	vector<tuple<Person, Relationship, Person>> m_relations;
public:
	void add_parent_and_child(const Person& parent, const Person& child) {
		m_relations.push_back({ parent, Relationship::parent, child });
		m_relations.push_back({ child, Relationship::child, parent });
	}

	// Inherited via RelationshipBrowser
	vector<Person> find_all_children_of(const string& name) override {
		vector<Person> result;
		for (auto&& [first, rel, second] : m_relations) {
			if (first.m_name == name && rel == Relationship::parent) {
				result.push_back(second);
			}
		}
		return result;
	}
};

struct Research { // High-level
	Research(RelationshipBrowser& browser) {
		const string john{ "John" };
		auto children_of_john = browser.find_all_children_of(john);
		for (auto &child: children_of_john) {
			cout << "John has a child called " << child.m_name << "\n";
		}
	}
	//Research(const Relationships& relationships) {
	//	auto& relations = relationships.m_relations;
	//	for (auto&& [first, rel, second] : relations) {
	//		if (first.m_name == "John" && rel == Relationship::parent) {
	//			cout << "John has a child called " << second.m_name << endl;
	//		}
	//	}
	//}
};

//main_20210201_1306
int main() {
	Person parent{ "John" };
	Person child1{ "Chris" };
	Person child2{ "Matt" };
	
    Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);
	
    RelationshipBrowser &rb = relationships;
	Research reh_(rb);

	return 0;
}
