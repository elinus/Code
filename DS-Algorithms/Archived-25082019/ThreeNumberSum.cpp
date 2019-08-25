#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

bool sorter(const vector<int> &v1, const vector<int> &v2) {
    if (v1[0] != v2[0]) {
        return v1[0] < v2[0];
    } else if (v1[1] != v2[1]) {
        return v1[1] < v2[1];        
    } else {
        return v1[2] < v2[2];
    }

}

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int> > res;

    for(int i = 0; i < array.size()-2; i++) {
        unordered_set<int> hash;
        int curr_sum = targetSum - array[i]; 
        for(int j = i+1; j < array.size() ; j++) {
            int x = targetSum - (array[i] + array[j]);
            if (hash.find(x) != hash.end()) {
                vector<int> vres;
                vres.push_back(array[i]);
                vres.push_back(array[j]);
                vres.push_back(curr_sum - array[j]);
                sort(vres.begin(), vres.end());
                res.push_back(vres);
            } else {
                hash.insert(array[j]);
            }
        }
    }
    sort(res.begin(), res.end(), sorter);
    return res;
}

int main (int argc, char const *argv[])
{
    vector<int> array = {12, 3, 1, 2, -6, 5, -8, 6};
    vector<vector<int> > res = threeNumberSum(array, 0);
    for (auto it1 = res.begin(); it1 != res.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) { 
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}

