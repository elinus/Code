#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>

std::string FetchDataFromDB(std::string received_data) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return "DB_" + received_data;
}

std::string FetchDataFromFile(std::string received_data) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return "File_" + received_data;
}


int main (int argc, char *argv[]) 
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::future<std::string> fromDb = std::async(std::launch::async, FetchDataFromDB, "Data");
    std::string fromFile = FetchDataFromFile("Data");
    std::string dbData = fromDb.get();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << diff << std::endl;
    std::string data = dbData + " :: " + fromFile;
    std::cout << data << std::endl;
    return 0;
}

