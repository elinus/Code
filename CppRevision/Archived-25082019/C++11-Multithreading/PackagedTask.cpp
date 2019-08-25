#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <future>

std::string getDataFromDB(std::string data) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "DB_" + data;
}

int main(int argc, char const *argv[])
{
    std::packaged_task<std::string(std::string)> task(getDataFromDB);
    std::future<std::string> future_db_data = task.get_future();
    std::thread th(std::move(task), "Arg");
    th.join();
    std::string data = future_db_data.get();
    std::cout << "Data => " << data << std::endl;
    return 0;
}

