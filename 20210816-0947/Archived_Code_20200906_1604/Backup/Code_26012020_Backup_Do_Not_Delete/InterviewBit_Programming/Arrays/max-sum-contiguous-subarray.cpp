#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(const vector<int>& A) {
    int n = A.size();
    int curSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        curSum += A[i];
        maxSum = max(curSum, maxSum);
        if (curSum < 0) {
            curSum = 0;
        }
    }
    return maxSum;
}

int main (int argc, char *argv[]) {
    cout << maxSubArray({-2, -3, 4, -1, -2, 1, 5, -3}) << "\n";
    return 0;
}

