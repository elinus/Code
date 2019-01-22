#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Wallet {
    public:
        Wallet() : money(0) {}
        void add(int amt) {
            //mutex.lock();
            std::lock_guard<std::mutex> lg_(mutex);
            for (int i = 0; i < amt; i++) {
                money++;
            }
            //mutex.unlock();
        }
        int get() {
            return money;
        }
    private:
        int money;
        std::mutex mutex;
};


int testMultithreadedWallet() {
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(&Wallet::add, &walletObject, 1000));
    }

    for (int i = 0; i < threads.size() ; i++) {
        threads[i].join();
    }
    return walletObject.get();
}

int main()
{

    int val = 0;
    for (int k = 0; k < 20; k++) {
        if ((val = testMultithreadedWallet()) != 5000) {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
        } else {
            std::cout << "Wallet update success!" << std::endl;
        }
    }
    return 0;
}
