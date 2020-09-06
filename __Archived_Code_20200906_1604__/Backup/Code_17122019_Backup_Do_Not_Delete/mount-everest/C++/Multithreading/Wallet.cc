#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Wallet {
    private:
        int m_Money;
        std::mutex mtx;
    public:
        Wallet() : m_Money(0) {}
        int GetMoney() { return m_Money; }
        void AddMoney(int money) {
            //mtx.lock();
            std::lock_guard<std::mutex> lck(mtx);
            for (int i = 0; i < money; i++)
            {
                m_Money++;
            }
            //mtx.unlock();
        }
};


int TestMultithreadedWallet() {
    Wallet walletObj;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(&Wallet::AddMoney, &walletObj, 1000));
    }
    for (int i = 0; i < 5; ++i)
    {
        threads[i].join();
    }
    return walletObj.GetMoney();
}

int main (int argc, char *argv[]) 
{
    int k = 0;
    int val = 0;
    for (int i = 0; i < 10; i++)
    {
        if ((val = TestMultithreadedWallet()) != 5000)
        {
            std::cout << "Error: Wallet total is " << val << "\n";
        }
    }
    return 0;
}

