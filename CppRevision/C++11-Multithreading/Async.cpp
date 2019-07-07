#include <iostream>
#include <thread>
#include <chrono>
#include <string>

std::string fetchDataFromDB(std::string data) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "DB_" + data;
}

std::string fetchDataFromFile(std::string data) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "FILE_" + data;
}

int main(int argc, char const *argv[])
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::string db_data = fetchDataFromDB("Data");
    std::string file_data = fetchDataFromFile("Data");
    auto end = std::chrono::system_clock::now();
    std::chrono::seconds diff = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Total time diff = " << diff.count() << " Seconds."<< std::endl;
    std::string data = db_data + " :: " + file_data;
    std::cout << "Data => " << data << std::endl;
    return 0;
}

