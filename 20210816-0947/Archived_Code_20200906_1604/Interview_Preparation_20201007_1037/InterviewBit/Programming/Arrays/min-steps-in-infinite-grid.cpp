#include <bits/stdc++.h>

int distance(int x1, int x2, int y1, int y2) {
    int xDiff = x1 > x2 ? x1 - x2 : x2 -x1;
    int yDiff = y1 > y2 ? y1 - y2 : y2 -y1;
    return xDiff > yDiff ? xDiff : yDiff;
}

int coverPoints(std::vector<int> & A, std::vector<int> & B) {
    int sum = 0;
    for (int i = 0; i < A.size()-1; i++) {
        sum += distance(A[i], A[i+1], B[i], B[i+1]);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
