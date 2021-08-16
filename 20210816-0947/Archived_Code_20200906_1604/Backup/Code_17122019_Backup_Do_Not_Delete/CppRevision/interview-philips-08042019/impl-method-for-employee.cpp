#include <iostream>
#include <vector>

class Employee {
    private:
        char *name;
        int age;
    public:
        Employee() {
            name = new char[0];
            age = 0;
            std::cout << "Default Constructor: " << this << std::endl;
        }
        Employee(const char *name, int age) {
            if (name != nullptr) {
                size_t len = 0;
                while (name[len] != '\0') len++;
                this->name = new char[len+1];
                for (int i = 0; i <= len; i++) {
                    this->name[i] = name[i];
                }
                this->age = age;
            } else {
                name = new char[0];
                age = 0;
            }
            std::cout << "Parameterized Constructor: " << this << std::endl;
        }
        ~Employee() {
            if (name != nullptr) {
                delete [] name;
            }
            std::cout << "Destructor: " << this << std::endl;
        }
        Employee(const Employee &other) {
            size_t len = 0;
            while (other.name[len] != '\0') len++;
            name = new char[len+1];
            for (int i = 0; i <= len; i++) {
                name[i] = other.name[i];
            }
            age = other.age;
            std::cout << "Copy Constructor: " << this << std::endl;
        }
        Employee & operator =(const Employee &other) {
            if (this != &other) {
                size_t len = 0;
                while (other.name[len] != '\0') len++;
                delete [] name;
                name = new char[len+1];
                for (int i = 0; i <= len; i++) {
                    this->name[i] = other.name[i];
                }
                age = other.age;
            }
            return *this;
            std::cout << "Assignment Operator: " << this << std::endl;
        }
        Employee(Employee && other) {
            name = other.name;
            age = other.age;
            other.name = nullptr;
            std::cout << "Move Constructor: " << this << std::endl;
        }
        Employee & operator =(Employee && other) {
            if (this != &other) {
                delete [] name;
                name = other.name;
                age = other.age;
                other.name = nullptr;
                std::cout << "Move Assignment: " << this << std::endl;
            }
            return *this;
        }
        friend std::ostream & operator << (std::ostream & out, const Employee & emp) {
            out << "name = ";
            size_t len = 0;
            while (emp.name[len] != '\0') {
                out << emp.name[len++];
            }
            out << ", age = " << emp.age;
            return out;
        }
        friend std::istream & operator >> (std::istream & in, Employee & emp) {
            char *name = new char[1000];
            int age = 0;
            std::cout << "Enter name = ";
            in >> name;
            std::cout << "Enter age = ";
            in >> age;
            emp = Employee(name, age);
            delete [] name;
            return in;
        }
};

Employee getEmployee() {
    Employee obj;
    return obj;
}

int main (int argc, char const *argv[])
{
    Employee e1; 
    std::cout << e1 << std::endl; 
    std::cout << "\n\n";
    
    Employee e2("elinus", 14);
    std::cout << e2 << std::endl;
    std::cout << "\n\n";

    Employee e3(e2);
    std::cout << e3 << std::endl;
    std::cout << "\n\n";

    Employee e4("mourys", 20);
    e4 = e3;
    std::cout << e4 << std::endl;
    std::cout << "\n\n";

    Employee e5;
    std::cin >> e5;
    std::cout << e5 << std::endl;
    std::cout << "\n\n";

    std::vector<Employee> empVec;
    empVec.push_back(getEmployee());
    std::cout << "\n\n";
    
    Employee e6;
    e6 = getEmployee();
    std::cout << e6 << std::endl;
    std::cout << "\n\n";
    return 0;
}

