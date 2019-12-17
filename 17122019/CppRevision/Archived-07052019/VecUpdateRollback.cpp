#include <iostream>
#include <vector>

using namespace std;

void foo(vector<int> &vec1, vector<int> &vec2, int val) {
    vec1.push_back(val);
    try {
        vec2.push_back(val);
    } catch (...) {
        cout << "second vector update failed!" << endl;
        vec1.pop_back();
    }
}

void bar(vector<int> &vec1, vector<int> &vec2, int val) {
    vec1.push_back(val);
    try {
        std::bad_alloc excp;
        throw excp;
        vec2.push_back(val);
    } catch (...) {
        cout << "second vector update failed!" << endl;
        vec1.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vec1;
    vector<int> vec2;
    foo(vec1, vec2, 14);
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;

    bar(vec1, vec2, 14);
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;
    return 0;
}
