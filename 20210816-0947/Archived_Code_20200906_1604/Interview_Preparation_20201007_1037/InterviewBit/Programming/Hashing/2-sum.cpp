#include <bits/stdc++.h>

template <typename DataType>
void print(const std::vector<DataType> &vec) {
    copy(vec.begin(), vec.end(), std::ostream_iterator<DataType>(std::cout, " "));
    std::cout << "\n";
}

struct TwoSum {
    int index1;
    int index2;
    TwoSum(int i, int j) {
        index1 = i;
        index2 = j;
    }
};

struct CompareIndex {
    bool operator()(const TwoSum& lhs, const TwoSum& rhs) {
        if (lhs.index2 < rhs.index2) return 1;
        if (lhs.index2 == rhs.index2 && lhs.index1 < rhs.index1) return 1;
        return 0;
    }
};

std::vector<int> twoSum(const std::vector<int> &A, int B) {
    std::unordered_map<int, int> umap;
    std::vector<TwoSum> sol;
    for (auto i = 0; i < A.size(); i++) {
        if (umap.find(B - A[i]) != umap.end()) {
            sol.push_back({ umap[B - A[i]] + 1, i + 1});
            // return { umap[B - A[i]] + 1, i + 1};
        } else {
            umap[A[i]] = i;
        }
    }
    if (sol.empty()) return {};
    sort(sol.begin(), sol.end(), CompareIndex());
    for (int i = 0; i < sol.size(); ++i) {
         std::cout << sol[i].index1 << " " << sol[i].index2 << "\n"; 
    }
    return { sol[0].index1, sol[0].index2 };
}



int main(int argc, char const *argv[])
{
    std::vector<int> vec = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
    int target = -3;
    twoSum(vec, target);
    // std::vector<TwoSum> vec1 = {{1, 2}, {5, 2}, {3, 2}, {0, 1}, {0, 0}};
    // sort(vec1.begin(), vec1.end(), CompareIndex());
    // print(twoSum(vec, target));
    // for (int i = 0; i < vec1.size(); ++i) {
    //     std::cout << vec1[i].index1 << " " << vec1[i].index2 << "\n"; 
    // }
    return 0;
}
