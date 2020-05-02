#include <iostream>
#include <string>
#include <set>

using namespace std;

string s1 = "asdfkjeghfalawefhaef";

int main (int argc, char *argv[]) {
    string coins = "dabbcabcd";
    coins = s1;
    set<char> set_(coins.begin(), coins.end());
    for (auto i = set_.begin(); i != set_.end(); ++i) {
        cout << *i << " ";
    }
    cout << "\n\n";

    int s = set_.size();
   
    set<char> _set;
    map<char, int> _map;
    for

    while (s <= coins.size()) {
        for (int i = 0; i < coins.size(); ++i) {
            
            if ((i + s) <= coins.size()) {
                string str = coins.substr(i, s);
                cout <<  str << endl;
            }
        }
        s++;
    }

    return 0;
}

