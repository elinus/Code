#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

template <typename T>
void print(const vector<T> &vec)
{
    cout << __func__ << endl;
    copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &vec)
{
    out << __func__ << endl;
    for (const auto &elem : vec)
    {
        out << elem << " ";
    }
    return out;
}

int main(int argc, char const *argv[])
{
    vector<string> names{"Sunil", "Akanksha", "Coco", "Zaki"};
    print(names);
    cout << names << endl;
    for_each(names.begin(), names.end(), [](const auto &elem) {
        cout << __func__ << " : " << elem << "\n";
    });
    return 0;
}
