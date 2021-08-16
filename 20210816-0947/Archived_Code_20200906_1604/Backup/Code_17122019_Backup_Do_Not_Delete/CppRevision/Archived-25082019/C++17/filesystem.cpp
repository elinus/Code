#include <iostream>
#include <cassert>
#include <experimental/filesystem>
namespace filesys = std::experimental::filesystem;
/*
   Check if given string path is of a file
   */
bool checkIfFIle(std::string filePath)
{
    try {
        // Create a Path object from given path string
        filesys::path pathObj(filePath);
        // Check if path exists and is of a regular file
        if (filesys::exists(pathObj) && filesys::is_regular_file(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e)
    {
        std::cout << e.what() << std::endl;
    }
    return false;
}
/*
   Check if given string path is of a Directory
   */
bool checkIfDirectory(std::string filePath)
{
    try {
        // Create a Path object from given path string
        filesys::path pathObj(filePath);
        // Check if path exists and is of a directory file
        if (filesys::exists(pathObj) && filesys::is_directory(pathObj))
            return true;
    }
    catch (filesys::filesystem_error & e)
    {
        std::cout << e.what() << std::endl;
    }
    return false;
}
int main() {

    std::string filePath = "/home/elinus/Code/CppRevision/a.out";

    // Try to check file that actually exists
    // It should return true
    bool result = checkIfFIle(filePath);

    assert(result == true);

    // Try to check if directory for file path
    // It should return false, because thats a file.
    result = checkIfDirectory(filePath);

    assert(result == false);

    std::string dirPath = "/home/elinus/Code/CppRevision/C++17";

    // Try to check directory that actually exists
    // It should return true
    result = checkIfDirectory(dirPath);

    assert(result == true);

    dirPath = "/home/elinus/foo/";

    // Try to check directory that don't exists
    // It should return false
    result = checkIfDirectory(dirPath);

    assert(result == false);
    /*
    // Try to check if file with directory path
    // It should return false
    result = checkIfFIle(dirPath);

    assert(result == false);
    */
    return 0;
}
