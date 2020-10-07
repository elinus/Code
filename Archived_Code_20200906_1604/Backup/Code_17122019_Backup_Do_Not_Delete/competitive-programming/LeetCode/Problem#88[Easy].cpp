/*
 * https://leetcode.com/problems/merge-sorted-array/
 */
#include <iostream>
#include <vector>

class Solution {
    public:
        void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
            std::vector<int> res((m + n), 0);
            for (int i = 0; i < (m+n); ++i) {

            }
        }
};

int main(int argc, char const *argv[])
{
    std::vector<int> v1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> v2 = {2, 5, 6};
    int m = 3, n = 3;
    Solution sobj;
    sobj.merge(v1, 3, v2, 3);
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}

