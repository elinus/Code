#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]) {
                    count++;
                }
            }
            int j = 0;
            for (int i = 0; i < nums.size() && j < count; i++) {
                if (nums[i]) {
                    nums[j++] = nums[i];
                }
            }
            int zeros = nums.size() - count;
            j = nums.size() - 1;
            for (int i = zeros; i > 0; --i) {
                nums[j--] = 0;
            }
        }
};

int main() {

    vector<int> vec = {0, 1, 2, 3, 0, 4, 5, 0, 6, 7, 0, 8, 9, 0};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    Solution obj;
    obj.moveZeroes(vec);
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;

}
