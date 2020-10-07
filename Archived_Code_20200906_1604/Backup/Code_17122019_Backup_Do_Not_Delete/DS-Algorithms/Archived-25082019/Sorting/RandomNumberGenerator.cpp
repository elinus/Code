#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

int main (int argc, char const *argv[])
{
    srand(time(0));
    vector<int> vec(10000);
    int val;
    for (int i = 0; i < 10000; i++) {
        val = rand() % 10000;
        //cout << val << " ";
        vec[i] = val;
    }
    //cout << "\n";

    auto start = chrono::system_clock::now();
    sort(vec.begin(), vec.end());
    auto end = chrono::system_clock::now();
    cout << "time elapsed = " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "\n";

    /*
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    */
    return 0;
}

