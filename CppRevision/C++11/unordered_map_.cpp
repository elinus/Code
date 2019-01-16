#include <iostream>
#include <unordered_map>
#include <string>

int main (int argc, char *argv[])
{
    std::unordered_map<std::string, int> umap;
    umap.insert({"elinus", 30});
    umap.insert({"aks", 28});
    umap.insert({"sweeet", 24});

    for (std::pair<std::string, int> elem: umap) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::unordered_map<std::string, int> wmap({
            {"First", 1},
            {"Second", 2},
            {"Third", 3},
            {"Fourth", 4},
            {"Fifth", 5}});
    auto it = wmap.begin();
    
    while (it != wmap.end()) {
        if (it->first[0] == 'F') {
            it = wmap.erase(it);
        } else {
            it++;
        }
    }

    for(auto elem: wmap){
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    return 0;
}

