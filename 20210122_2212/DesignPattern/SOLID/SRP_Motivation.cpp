#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Journal {
	string m_title;
	vector<string> m_entries;
public:
	explicit Journal(const string& title) : m_title{ title } {}
	void add_entries(const string& entry) {
		static uint32_t count = 1;
		m_entries.push_back(to_string(count++) + ": " + entry);
	}
	auto get_entries() const {
		return m_entries;
	}
	void save(const string& filename) {
		ofstream ofs(filename);
		for (auto& s : m_entries) ofs << s << endl;
	}
};

// main_20210201_1306
int main_20210201_1306() {
	Journal journal("Dear Coco & Zaki");
	journal.add_entries("I ate a bug");
	journal.add_entries("I cried today");
	journal.save("CocoZakiJournal.txt");
	return 0;
}