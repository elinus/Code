#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int first = 0, second = 0, curr = -1, prev = -1, index = 0;
        int mid = (size1 + size2) / 2;
        while (first < size1 && second < size2 && index <= mid) {
            prev = curr;
            if (nums1[first] < nums2[second]) {
                curr = nums1[first++];
            } else {
                curr = nums2[second++];
            }
            index++;   
        }
        while (first < size1 && index <= mid) {
            prev = curr;
            curr = nums1[first++];
            index++;   
        }
        while (second < size2 && index <= mid) {
            prev = curr;
            curr = nums2[second++];
            index++;   
        }
        if ((size1 + size2) & 1)
            return static_cast<double>(curr);
        else
            return (static_cast<double>(prev) + static_cast<double>(curr)) / 2;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<int> v1 = {1, 2}, v2 = {3, 4};
    std::cout << sol.findMedianSortedArrays(v1, v2) << "\n";
    return 0;
}
