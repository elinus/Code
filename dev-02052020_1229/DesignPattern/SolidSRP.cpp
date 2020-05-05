#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Journal {
    string title;
    vector<string> entries;
    explicit Journal(const string& title)
        : title(title)
    {}
    void add(const string& entry);
    void save(const string& filename); // persistence is separate concern
};

void Journal::add(const string& entry) {
    static int count = 1;
    entries.push_back(to_string(count++) + " : " + entry);
}

void Journal::save(const string& filename) {
    ofstream ofs(filename);
    for (auto& s: entries) {
        ofs << s << endl;
    }
}

struct PersistenceManager {
    static void save(const Journal& journal, const string& filename) {
        ofstream ofs(filename);
        for (auto& s: journal.entries) {
            ofs << s << endl;
        }
    }
};

int main (int argc, char *argv[]) {
    Journal journal {"elinus-journal"};
    journal.add("sweeet");
    journal.add("coco");
    //journal.save("dairy.txt");
    PersistenceManager pm;
    pm.save(journal, "pm-dairy.txt");
    return 0;
}

