#include <iostream>
#include <thread>
#include <chrono>

void do_some_work() {
    std::cout << "tid=" << std::this_thread::get_id() << ", doing some work..\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

struct background_task {
    void operator()() const {
        std::cout << "tid=" << std::this_thread::get_id() << ", background task..\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

int main (int argc, const char *argv[]) {

    std::thread t1 { do_some_work };
    std::this_thread::sleep_for(std::chrono::seconds(1));

    background_task bt;
    std::thread t2 { bt }, t3 { background_task() };

    std::thread t4([] {
            std::cout << "tid=" << std::this_thread::get_id() << ", lambda task..\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "All threads joined. Exiting main=" << std::this_thread::get_id() << "\n";
    return 0;
}

