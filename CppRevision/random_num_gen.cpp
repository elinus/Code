#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[])
{
    vector<int> vec(10);
    generate(vec.begin(), vec.end(), rand);
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

