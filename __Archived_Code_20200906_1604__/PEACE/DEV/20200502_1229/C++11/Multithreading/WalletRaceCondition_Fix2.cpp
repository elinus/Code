#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>
#include <mutex>

class Wallet {
private:
    int m_Money;
    std::mutex m_Mutex;
public :
    Wallet() : m_Money(0) {}
    int getMoney() {
        return m_Money;
    }
    void addMoney(int amount) {
        std::lock_guard<std::mutex> lock(m_Mutex);
        for (size_t i = 0; i < amount; i++) {
            m_Money++;
        }
    }
};

int TestMultithreadedWallet() {
    Wallet wallet_obj;
    std::vector<std::thread> wallet_t_vec_;
    for (size_t i = 0; i < 5; i++) {
        wallet_t_vec_.push_back(std::thread(&Wallet::addMoney, &wallet_obj, 1000));
    }
    std::for_each(wallet_t_vec_.begin(), wallet_t_vec_.end(), std::mem_fn(&std::thread::join));
    return wallet_obj.getMoney();
}

int main(int argc, char const *argv[]) {
    int val = 0;
    for (size_t i = 0; i < 100; i++) {
        if ((val = TestMultithreadedWallet()) != 5000) {
            std::cout << "Error :: wallet money = " << val << std::endl;
        }
    }
    
    return 0;
}
