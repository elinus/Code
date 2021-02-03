#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Database { // Dependency
  virtual int32_t get_population(const string &city) = 0;
};

class SingletonDatabase : Database {
  map<string, uint32_t> m_country;
  SingletonDatabase() {
    ifstream ifs("country.txt");
    string city, population;
    while (getline(ifs, city)) {
      getline(ifs, population);
      m_country[city] = stoi(population);
    }
  }

public:
  SingletonDatabase(const SingletonDatabase &) = delete;
  SingletonDatabase &operator=(const SingletonDatabase &) = delete;
  static SingletonDatabase &get() {
    static SingletonDatabase db_instance;
    return db_instance;
  }

  int32_t get_population(const string &city) override {
    return m_country[city];
  }
};

class DummyDatabase : public Database {
  map<string, int32_t> m_countries;

public:
  DummyDatabase() : m_countries{{"alpha", 1}, {"beta", 2}, {"gamma", 3}} {}
  int32_t get_population(const string &country) override {
    return m_countries[country];
  }
};

class ConfigurableRecordFinder {
  Database &db; // Dependency Injection

public:
  ConfigurableRecordFinder(Database &db) : db{db} {}
  int32_t total_population(const vector<string> &countries) {
    int32_t result = 0;
    for (auto &country : countries)
      result += db.get_population(country);
    return result;
  }
};

int main(int argc, char const *argv[]) {
  DummyDatabase db;
  ConfigurableRecordFinder rf(db);
  cout << rf.total_population({"alpha", "beta", "gamma"}) << "\n";

  return 0;
}
