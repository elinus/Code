#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hash;
    auto it_hash = hash.begin();
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      it_hash = hash.find(target - nums[i]);
      if (it_hash == hash.end()) {
        hash[nums[i]] = i;
      } else {
        result.push_back(hash[target - nums[i]]);
        result.push_back(i);
        break;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 18;
  Solution so;
  std::vector<int> sols = so.twoSum(nums, target);
  for (int i = 0; i < sols.size(); i++) {
    std::cout << sols[i] << "\n";
  }
  return 0;
}
