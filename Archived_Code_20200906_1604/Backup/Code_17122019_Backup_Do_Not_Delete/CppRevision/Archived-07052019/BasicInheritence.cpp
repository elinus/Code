#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        string m_name;
        int m_age;
        Person(string name = "", int age = 0)
            : m_name(name), m_age(age) 
        {
            cout << "Person" << endl;
        }
        string getName() const {
            return m_name;
        }
        int getAge() const {
            return m_age;
        }
};

class BaseballPlayer : public Person {
    public:
        double m_battingAverage;
        int m_homeRuns;
        BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
            : m_battingAverage(battingAverage), m_homeRuns(homeRuns) 
        {
            cout << "Baseball Player" << endl;
        }
};

class Emplyoee : public Person {
    public:
        double m_hourlySalary;
        long m_employeeId;
        Emplyoee(string name = "elinus", double hourlySalary = 0.0, long employeeId = 0)
            : Person(name), m_hourlySalary(hourlySalary), m_employeeId(employeeId) 
        {
            cout << "Employee" << endl;
        }
        void printNameAndSalary() const {
            cout << m_name << ": " << m_hourlySalary << endl;
        }
};

int main (int argc, char const *argv[])
{
    BaseballPlayer elin;
    elin.m_name = "elin";
    cout << elin.getName() << "\n\n";

    Emplyoee frank;
    cout << frank.getName() << "\n";
    frank.m_name = "Frank";
    frank.m_hourlySalary = 100.00;
    frank.printNameAndSalary();

    return 0;
}

