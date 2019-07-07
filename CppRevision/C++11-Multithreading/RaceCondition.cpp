#include <iostream>
#include <thread>
#include <vector>

class Wallet {
    private:
        int mMoney;
    public:
        Wallet() : mMoney(0) {}
        int getMoney() { return mMoney; }
        void addMoney(int money) {
            for (int i = 0; i < money; ++i) {
                mMoney++;
            }
        }
};

int testMultithreadedWallet() {
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for (int i = 0; i < 5; i++) {
        threads[i].join();
    }
    return walletObject.getMoney();
}

int main(int argc, char const *argv[])
{
    int val = 0;
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if ((val = testMultithreadedWallet()) != 5000) {
            count++;
            std::cout << "Error at count " << i 
                << " Money in Wallet = " << val << std::endl; 
        }
    }
    std::cout << "Error's count = " << count << std::endl;
    return 0;
}

