#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Journal {
private:
  std::string title;
  std::vector<std::string> entries;

public:
  explicit Journal(const std::string &title) : title{title} {}
  void add_enteries(const std::string &entry) {
    static uint_fast32_t count = 1;
    entries.push_back(std::to_string(count++) + ": " + entry);
  }
  auto get_entries() const { return entries; }
  //   void save(const std::string &filename) {
  //     std::ofstream ofs(filename);
  //     for (auto &entry : entries) {
  //       ofs << entry << std::endl;
  //     }
  //   }
};

struct PersistanceManager {
  static void save(const Journal &journal, const std::string &filename) {
    std::ofstream ofs(filename);
    for (auto &entry : journal.get_entries()) {
      ofs << entry << std::endl;
    }
  }
};

int main(int argc, char const *argv[]) {
  Journal journal("cat-journal");
  journal.add_enteries("Coco");
  journal.add_enteries("Zaki");
  PersistanceManager::save(journal, "CatJournal.txt");
  return 0;
}
