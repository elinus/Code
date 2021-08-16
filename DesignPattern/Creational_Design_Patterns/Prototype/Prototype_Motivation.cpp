#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Office {
  string street;
  string city;
  int32_t cubical;
  Office(string street, string city, int32_t cubical)
      : street{street}, city{city}, cubical{cubical} {}
};
/* Motivation -----------------------------------------------------------*/
// struct Employee {
//   string name;
//   Office office;
//   Employee(string name, Office office) : name{name}, office{office} {}
// };

/* More pragmatic approach --------------------------------------------*/
// struct Employee {
//   string name;
//   const Office *office;
//   Employee(string name, Office *office) : name{name}, office{office} {}
// };

// static Office LondonOffice{"123 East Dr", "London", 123};
// static Office BengaluruOffice{"RMZ Ecoworld ORR", "London", 123};

class Employee {
  string name;
  Office *office;
  Employee(string name, Office *office) : name{name}, office{office} {}
  friend class EmployeeFactory;

public:
  Employee(const Employee &other)
      : name{other.name}, office{new Office{*other.office}} {}
  Employee &operator=(const Employee &other) {
    if (&other == this)
      return *this;
    delete office;
    name = other.name;
    office = new Office{*other.office};
    return *this;
  }
  friend ostream &operator<<(ostream &out, const Employee &emp) {
    return out << emp.name << " works at " << emp.office->street << " "
               << emp.office->city << " seats @" << emp.office->cubical << endl;
  }
};

class EmployeeFactory {
  static Employee main;
  static Employee aux;
  static unique_ptr<Employee> NewEmployee(string name, int32_t cubical,
                                          Employee &proto) {
    auto emp = make_unique<Employee>(proto);
    emp->name = name;
    emp->office->cubical = cubical;
    return emp;
  }

public:
  static unique_ptr<Employee> NewMainOfficeEmployee(string name,
                                                    int32_t cubical) {
    return NewEmployee(name, cubical, main);
  }
  static unique_ptr<Employee> NewAuxOfficeEmployee(string name,
                                                   int32_t cubical) {
    return NewEmployee(name, cubical, aux);
  }
};
// Static Member Initialization
Employee EmployeeFactory::main{"", new Office{"123 East Dr", "London", 123}};
Employee EmployeeFactory::aux{"",
                              new Office{"RMZ Ecoworld ORR", "London", 123}};

struct Animal {
  virtual ~Animal() = default;
  virtual unique_ptr<Animal> create() = 0;
  virtual unique_ptr<Animal> clone() = 0;
};

struct Dog : Animal {
  virtual unique_ptr<Animal> create() override { return make_unique<Dog>(); };
  virtual unique_ptr<Animal> clone() override {
    return make_unique<Dog>(*this);
  }
};

struct Cat : Animal {
  virtual unique_ptr<Animal> create() override { return make_unique<Cat>(); };
  virtual unique_ptr<Animal> clone() override {
    return make_unique<Cat>(*this);
  }
};

void who_am_i(Animal *who) {
  auto new_who = who->create();
  auto dup_who = who->clone();
  delete who;
}

int main(int argc, char const *argv[]) {
  /* Motivation -----------------------------------------------------------*/
  //   Employee john{"John Doe", Office{"123 East Dr", "London", 123}};
  //   Employee jane{"Jane Doe", Office{"123 East Dr", "London", 124}};
  //   Employee jack{"jack Doe", Office{"123 ORR", "Bengaluru", 300}};

  /* More pragmatic approach --------------------------------------------*/
  //   Employee john{"John Doe", &LondonOffice};
  //   Employee jane{"Jane", &LondonOffice};
  //   Employee jack{"Jack Doe", &BengaluruOffice};

  auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);
  auto jack = EmployeeFactory::NewAuxOfficeEmployee("jack Doe", 123);
  cout << *jane << endl << *jack << endl;
  return 0;
}
