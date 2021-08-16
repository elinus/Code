#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class NumberPrintUtil {
private: 
	int start_;
	int end_;
	std::mutex mutex_;
	std::condition_variable cond_var_;
public:
	NumberPrintUtil(int start, int end) : start_{start}, end_{end}
	{}
	void print_odd() {
		while (start_ < end_) {
			std::unique_lock<std::mutex> ul(mutex_);
			cond_var_.wait(ul, [this]() { return start_ % 2; });
			std::cout << "thread=" << std::this_thread::get_id() << ", num = " << start_ << std::endl;
			start_++;
			cond_var_.notify_one();
		}

		std::lock_guard<std::mutex> lg(mutex_);
		std::cout << "Exiting thread=" << std::this_thread::get_id() << std::endl;
	}
	void print_even() {
		while (start_ < end_) {
			std::unique_lock<std::mutex> ul(mutex_);
			cond_var_.wait(ul, [this]() { return !(start_ % 2); });
			std::cout << "thread=" << std::this_thread::get_id() << ", num = " << start_ << std::endl;
			start_++;
			cond_var_.notify_one();
		}
		std::lock_guard<std::mutex> lg(mutex_);
		std::cout << "Exiting thread=" << std::this_thread::get_id() << std::endl;
	}

};

//int main() {
//	NumberPrintUtil npu_obj(7, 50);
//	std::thread o_th(&NumberPrintUtil::print_odd, &npu_obj);
//	std::thread e_th(&NumberPrintUtil::print_even, &npu_obj);
//	if (o_th.joinable()) o_th.join();
//	if (e_th.joinable()) e_th.join();
//	std::cout << "Exiting main=" << std::this_thread::get_id() << " thread." << std::endl;
//	return 0;
//}