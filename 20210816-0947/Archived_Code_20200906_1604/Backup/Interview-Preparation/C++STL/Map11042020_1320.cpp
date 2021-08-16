#include <iostream>
#include <map>

using namespace std;

int main (int argc, char *argv[]) {
    map<int, int> m_;
    m_[0] = 0;
    m_[-1] = 1;
    m_[1] = 2;
    m_[-2] = 3;
    m_[2] = 4;
    for (auto it = m_.begin(); it != m_.end(); ++it) {
        cout << it->first << " " << it->second << "\n";
    }
    return 0;
}

