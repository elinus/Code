#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;

int coverPoints(vector<int>& A, vector<int>& B) {
    if (A.size() <= 1) return 0;
    assert(A.size() == B.size());
    
    int sum = 0;

    for(int i = 1; i < A.size(); i++) {
        sum += max(abs(A[i] - A[i-1]), abs(B[i] - B[i-1]));
    }
    return sum;
}

int main (int argc, char *argv[]) {
    vector<int> A { 0, 1, 1 };
    vector<int> B { 0, 1, 2 };
    std::cout << coverPoints(A, B) << "\n";
    return 0;
}

