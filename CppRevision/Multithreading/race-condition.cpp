#include <iostream>
#include <thread>
#include <vector>

class Wallet {
    public:
        Wallet() : money(0) {}
        void add(int amt) {
            for (int i = 0; i < amt; i++) {
                money++;
            }
        }
        int get() {
            return money;
        }
    private:
        int money;
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
        }
    }
    return 0;
}
