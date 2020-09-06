#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 14;
    int &refNum = num;
    cout << "refNum = " << refNum << endl;
    cout << "&refNum = " << &refNum  << " and &num = " << &num << endl;
    cout << "num = " << num << endl;
    cout << "++refNum = " << ++refNum << endl;
    cout << "num = " << num << endl;
    return 0;
}
