#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main (int argc, char *argv[])
{
    vector<int> v1;
    for (int i = 1; i <= 20; ++i) {
        v1.push_back(i);
    }
    print(v1);

    // Iterators 
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    for (auto it = v1.cbegin(); it != v1.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    for (auto it = v1.crbegin(); it != v1.crend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // Capacity
    cout << "Size: " << v1.size() << "\n";
    cout << "Capacity: " << v1.capacity() << "\n";
    cout << "Max Size: " << v1.max_size() << "\n";
    cout << "Empty: " << v1.empty() << endl;
    v1.shrink_to_fit();
    cout << "Size(after shrink to fit): " << v1.size() << "\n";
    cout << "Capacity(after shrink to fit): " << v1.capacity() << "\n";
    v1.resize(28);
    print(v1);
    cout << "Size(after resize): " << v1.size() << "\n";
    cout << "Capacity(after resize): " << v1.capacity() << "\n";
    
    // Element Access
    cout << v1[19] << "\n";
    cout << v1.at(19) << "\n";
    cout << v1.front() << "\n";
    cout << v1.back() << "\n";
    int *pos = v1.data();
    cout << "*pos = " << *pos << "\n";

    // Modifiers
    vector<int> v2;
    v2.assign(14, 20);
    cout << "v2 size = " << v2.size() << "\n";
    print(v2);
    v2.push_back(14);
    cout << "v2 size = " << v2.size() << "\n";
    v2.pop_back();
    cout << "v2 size = " << v2.size() << "\n";

    v2.insert(v2.begin(), 14);
    print(v2);
    v2.insert(v2.begin(), 5);
    v2.erase(v2.begin());

    v2.emplace(v2.begin(), 14);
    v2.emplace_back(14);
    print(v2);
    
    v2.clear();
    cout << "Size(after clear): " << v2.size() << "\n";
    cout << "Capacity(after clear): " << v2.capacity() << "\n";

    vector<int> v3;
    v3.push_back(14);
    v3.push_back(20);
    vector<int> v4;
    v4.push_back(24);
    v4.push_back(11);
    v4.push_back(16);
    print(v3);
    print(v4);
    v3.swap(v4);
    print(v3);
    print(v4);


    return 0;
}

