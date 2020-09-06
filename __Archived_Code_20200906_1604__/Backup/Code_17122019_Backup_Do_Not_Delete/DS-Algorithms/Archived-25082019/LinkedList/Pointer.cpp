#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
    int num = 14;
    int *p = &num;
    int **pp = &p;
    cout << "num = " << num << ", &num = " << &num << endl;
    cout << "*p = " << *p << ", p = " << p << endl;
    cout << "**pp = " << **pp << ", &p = " << &p << ", pp = " << pp << ", *pp = " << *pp << endl;
    return 0;
}

