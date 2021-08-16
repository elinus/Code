#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <vector>

using namespace std;

template<typename K>
void foo_limit() {
    cout << numeric_limits<K>::lowest() << endl;
}

template<typename K, typename V>
void foo(V const & val) {
    map<K, V> map_;
    map_.insert(map_.end(), make_pair(numeric_limits<K>::lowest(), val));
    for (auto it  = map_.begin(); it != map_.end(); ++it) {
        cout << it->first << " " << endl;
        for (auto its = it->second.begin(); its != it->second.end(); ++its) {
            cout << *its << " ";
        }
        cout << endl;
    }
}

int main (int argc, char *argv[]) {
    /*
    foo_limit<int>();
    foo_limit<long>();
    foo_limit<double>();
    foo_limit<unsigned int>();
    foo_limit<string>();
    */
    //vector<int> values = {14, 20, 25, 11, 16};
    //foo<int, vector<int>>(values);
    
    map<int, int> map_;
    map_[1] = 1;
    map_[2] = 2;
    map_[3] = 3;
    map_[4] = 4;
    map_[5] = 5;
    for (auto it = map_.begin(); it != map_.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "\n\n";
    auto itu = map_.lower_bound(5);
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(6);
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(7);
    if (itu == map_.end()) {
        cout << "end" << endl;
    }
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(-1);
    if (itu == map_.begin()) {
        cout << "begin" << endl;
    }
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(0);
    if (itu == map_.begin()) {
        cout << "begin" << endl;
    }
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(3);
    cout << itu->first << " " << itu->second << "\n";
    itu = map_.lower_bound(4);
    cout << itu->first << " " << itu->second << "\n";
    return 0;
}

