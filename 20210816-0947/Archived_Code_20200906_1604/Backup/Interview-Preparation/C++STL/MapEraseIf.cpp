#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <functional>

template<typename K, typename V>
int erase_if(std::map<K, V> & mapOfElemen, bool(* functor)(V)) {
    int totalDeletedElements = 0;
    auto it = mapOfElemen.begin();
    while(it != mapOfElemen.end()) {
        if(functor(it->second)) {
            totalDeletedElements++;
            it = mapOfElemen.erase(it);
        }
        else
            it++;
    }
    return totalDeletedElements;
}

bool isODD(int val) {
    if(val % 2 == 1)
        return true;
    else
        return false;
}
int main() {
    std::map<std::string, int> wordMap = {
        { "is", 6 },
        { "the", 5 },
        { "hat", 9 },
        { "at", 6 }
    };
    std::cout << "Map Entries Before Deletion" << std::endl;
    for (auto elem : wordMap)
        std::cout << elem.first << " :: " << elem.second << std::endl;
    
    int deletedCount = erase_if(wordMap, isODD);
    std::cout<<"Total elements deleted = "<<deletedCount<<std::endl;
    std::cout << "Map Entries After Deletion" << std::endl;
    
    for (auto elem : wordMap)
        std::cout << elem.first << " :: " << elem.second << std::endl;
    return 0;
}
