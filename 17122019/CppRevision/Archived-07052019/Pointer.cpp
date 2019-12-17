#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 14;
    int *pNum = &num;
    cout << "*pNum = " << *pNum << endl;
    cout << "pNum = " << pNum << endl;
    cout << "&pNum = " << &pNum << endl;
    *pNum = 20;
    cout << "*pNum = " << *pNum << endl;

    // double pointer
    int var = 24;
    int *ptr1 = &var;
    int **ptr2 = &ptr1;
    cout << "var = " << var
         << ", var addr. = " << &var << endl;
    cout << "*ptr1 = " << *ptr1
         << ", ptr1(pointing to) = " << ptr1
         << ", ptr1 addr(&ptr1) = " << &ptr1 << endl;
    cout << "**ptr2 = " << **ptr2
         << ", *ptr2 = " << *ptr2
         << ", ptr2(pointing to) = " << ptr2
         << ", ptr2 addr(&ptr2) = " << &ptr2 << endl;

    return 0;
}
