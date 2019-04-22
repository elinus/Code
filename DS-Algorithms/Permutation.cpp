#include <iostream>
#include <string>
#include <vector>

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void permute(std::string str, int left, int right) {
    if (left == right) {
        std::cout << str << std::endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            permute(str, left+1, right);
            swap(str[left], str[i]);
        }
    }

}

void permute(std::vector<int>& vec, int left, int right, std::vector<std::vector<int> >& result) {
    if (left == right) {
        result.push_back(vec);
    } else {
        for (int i = left; i <= right; i++) {
            swap(vec[left], vec[i]);
            permute(vec, left+1, right, result);
            swap(vec[left], vec[i]);
        }
    }

}

int main (int argc, char const *argv[])
{
    //std::string str("ABC");
    //permute(str, 0, str.length() - 1);
    std::vector<int> arr = {1, 2, 3};
    std::vector<std::vector<int> > result;
    permute(arr, 0, arr.size() - 1, result);
    for (auto it1 = result.begin(); it1 != result.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

