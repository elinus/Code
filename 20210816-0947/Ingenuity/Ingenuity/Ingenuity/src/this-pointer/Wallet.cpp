#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>
#include <mutex>

using namespace std;

class Wallet {
private:
	int m_money;
	std::mutex m_mutex;
public:
	Wallet() : m_money{ 0 }
	{}
	void add_money(int money) {
		for (int i = 0; i < money; i++) {
			std::lock_guard<std::mutex> l(m_mutex); // to fix race condition
			m_money++;
		}
	}
	int get_money() const {
		return m_money;
	}
};

int test_wallet_money() {
	Wallet wallet_obj;
	std::vector<std::thread> threads;

	for (int i = 0; i < 5; i++) {
		threads.push_back(std::thread(&Wallet::add_money, &wallet_obj, 1000));
	}
	for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	return wallet_obj.get_money();
}

//int main() {
//	for (int i = 0; i < 1000; i++) {
//		int wallet_money = test_wallet_money();
//		if (wallet_money != 5000) {
//			std::cout << "wallet#" << i << " money = " << wallet_money << std::endl;
//		}
//	}
//	return 0;
//}