#include <fstream>
#include <iostream>
#include <map>
#include <string>

class SingletonDatabase {
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
  int32_t get_population(const std::string &name) { return m_country[name]; }
};

int main(int argc, char const *argv[]) {
  std::cout << "Japan = " << SingletonDatabase::get().get_population("Japan")
            << std::endl;
  return 0;
}
