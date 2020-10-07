#include <iostream>
#include <ctime>
#include <string>

void GetTime(std::string date_) {
    tm tm_;
    tm_ = {0};
    strptime(date_.c_str(), "%m-%d-%Y %H:%M:%S", &tm_);
    mktime(&tm_);
    std::cout << tm_.tm_mday << " " << tm_.tm_mon + 1 << " " << tm_.tm_year + 1900 << "\n";
    std::cout << tm_.tm_hour << " " << tm_.tm_min + 1 << " " << tm_.tm_sec << "\n";
}

int main (int argc, const char *argv[]) {
    GetTime("01-02-2020 10:11:12");
    return 0;
}

