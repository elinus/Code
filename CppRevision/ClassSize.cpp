/*
 * NOTE:
 * $g++ -fdump-class-hierarchy -c ClassSize.cpp
 * */
#include <iostream>

using namespace std;

class Employee {
    public:
        Employee* m_pEmp;
        int m_age;
        static int s_id;
};

int main(int argc, char const *argv[]) {
    cout << "size of int = " << sizeof(int) << "\n";
    cout << "size of int* = " << sizeof(int *) << "\n";
    cout << "size of double = " << sizeof(double) << "\n";
    cout << "size of double* = " << sizeof(double *) << "\n";
    cout << "size of Employee = " << sizeof(Employee) << "\n";
    cout << "size of Employee* = " << sizeof(Employee *) << "\n";
    cout << "alignof = " << alignof(Employee) << "\n";
    return 0;
}

