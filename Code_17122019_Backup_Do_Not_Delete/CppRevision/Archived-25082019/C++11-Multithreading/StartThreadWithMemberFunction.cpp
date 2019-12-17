#include <iostream>
#include <thread>
#include <string>

class Task {
    public:
        void execute(std::string message) {
            for (int i = 0; i < 5; ++i) {
                std::cout << std::this_thread::get_id() << " :: " << i << " :: " << message << std::endl;
            }
        }
        static void command(std::string message) {
            for (int i = 0; i < 5; ++i) {
                std::cout << std::this_thread::get_id() << " :: " << i << " :: " << message << std::endl;
            }
        }
};

int main(int argc, char const *argv[])
{
    Task *taskObj = new Task();
    std::thread t1(&Task::execute, taskObj, "Hello!");

    std::thread t2(&Task::command, "Hey!");
    
    if (t1.joinable()) {
        t1.join();
    }
    
    if (t2.joinable()) {
        t2.join();
    }

    return 0;
}

