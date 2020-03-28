#include <iostream>
#include <experimental/filesystem>

namespace filesys = std::experimental::filesystem;

bool checkPath(std::string file_path) {
    filesys::path fp(file_path);
    try {
        if (filesys::exists(fp) && filesys::is_directory(fp)) 
            return true;
    } catch (filesys::filesystem_error & e) {
        std::cerr << e.what();
    }
    return false;
}

int main (int argc, char *argv[]) {
    std::cout << checkPath("/home/elinus/Code/Interview-Preparation/LANG/C++") << "\n";    
    return 0;
}

