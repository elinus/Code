#include <bits/stdc++.h>

using namespace std;

template <typename DataType>
void print(const vector<DataType> &vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<DataType>(cout, " "));
    cout << "\n";
}

vector<int> plusOne(vector<int> &A) {
    if (A.empty()) return {};
    std::vector<int> res(A.rbegin(), A.rend());
    while(res.size() > 0 && res.back() == 0) {
        res.pop_back();
    }
    if (res.empty()) return { 1 };
    int carry = 0;
    if ((res[0] + 1) > 9) {
        res[0] = 0;
        carry = 1;
    } else {
        res[0] += 1;
    }
    for (int i = 1; i < res.size(); i++) {
        if ((res[i] + carry) > 9) {
            res[i] = 0;
            carry = 1;
        } else {
            res[i] += carry;
            carry = 0;
        }
    }
    if (carry) {
        res.push_back(carry);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[]) {
    vector<int> v1 = { 1, 2, 3 };
    print(plusOne(v1));
    return 0;
}
