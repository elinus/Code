#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Database {
  virtual int32_t get_population(const std::string &name) = 0;
};

class SingletonDatabase : public Database {
private:
  std::map<std::string, int32_t> m_country;
  SingletonDatabase() {
    std::ifstream ifs("country.txt");
    std::string city, population;
    while (getline(ifs, city)) {
      getline(ifs, population);
      m_country[city] = std::stoi(population);
    }
  }

public:
  SingletonDatabase(const SingletonDatabase &) = delete;
  SingletonDatabase &operator=(const SingletonDatabase &) = delete;
  static SingletonDatabase &get() {
    static SingletonDatabase db;
    return db;
  }
  int32_t get_population(const std::string &name) override {
    return m_country[name];
  }
};

class DummyDatabase : public Database {
private:
  std::map<std::string, int32_t> m_country;

public:
  DummyDatabase() : m_country{{"alpha", 1}, {"beta", 2}, {"gamma", 3}} {}
  int32_t get_population(const std::string &name) override {
    return m_country[name];
  }
};

/* Testing class ----------------------------------------------------------*/
class ConfigurableRecordFinder {
private:
  Database &m_db;

public:
  ConfigurableRecordFinder(Database &db) : m_db{db} {}
  int32_t total_population(const std::vector<std::string> &countries) {
    int32_t result = 0;
    for (auto &country : countries) {
      result += m_db.get_population(country);
    }
    return result;
  }
};
/*-------------------------------------------------------------------------*/

int main(int argc, char const *argv[]) {
  std::cout << "Japan = " << SingletonDatabase::get().get_population("Japan")
            << std::endl;
  DummyDatabase db;
  ConfigurableRecordFinder rf(db);
  std::cout << rf.total_population({"alpha", "beta", "gamma"}) << std::endl;
  return 0;
}
