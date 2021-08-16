#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

std::condition_variable cZ, cO, cE;
std::mutex mtx;
int gNum = 1;

void Zero() { 
    std::unique_lock<std::mutex> lock(mtx);
    while (true) {
        std::cout << "0\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (gNum%2) {
            cO.notify_one();
        } else {
            cE.notify_one();
        }
        cZ.wait(lock);
    }
}

void Odd() {
    std::unique_lock<std::mutex> lock(mtx);
    while (true) {
        std::cout << gNum++ << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cZ.notify_one();
        cO.wait(lock);
    }
}

void Even() {
    std::unique_lock<std::mutex> lock(mtx);
    while (true) {
        std::cout << gNum++ << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cZ.notify_one();
        cE.wait(lock);
    }
}

int main (int argc, char *argv[]) {
    std::thread tz(Zero);
    std::thread to(Odd);
    std::thread te(Even);
    tz.join();
    to.join();
    te.join();
    return 0;
}

