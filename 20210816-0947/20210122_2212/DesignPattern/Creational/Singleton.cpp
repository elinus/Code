#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class SingletonDatabase {
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

  int32_t get_population(string city) { return m_country[city]; }
};

int main(int argc, char const *argv[]) {
  cout << "Japan : " << SingletonDatabase::get().get_population("Japan") << "\n";
  return 0;
}
