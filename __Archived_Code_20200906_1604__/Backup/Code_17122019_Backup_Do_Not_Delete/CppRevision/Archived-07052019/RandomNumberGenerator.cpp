#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        cout << rand() << endl;
    }
    return 0;
}

