#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    try {
        try {
            throw 14;
        } catch (int e) {
            cout << "Int exception caught. Value = " << e << endl;
            throw;
        }
    } catch (...) {
        cout << "An error occured!!" << endl;
    }
    return 0;
}
