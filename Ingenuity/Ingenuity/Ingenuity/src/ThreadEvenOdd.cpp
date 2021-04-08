#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

condition_variable g_cv;
mutex g_mtx;
int number = 1;

void printOdd() {
	while (number < 20) {
		unique_lock<mutex> ul(g_mtx);
		g_cv.wait(ul, []() { return (number % 2) == 1; });
		cout << __func__ << " : " << this_thread::get_id() << " # " << number << endl;
		number++;
		ul.unlock();
		g_cv.notify_all();
	}
}

void printEven() {
	while (number < 20) {
		unique_lock<mutex> ul(g_mtx);
		g_cv.wait(ul, []() { return (number % 2) == 0; });
		cout << __func__ << " : " << this_thread::get_id() << " # " << number << endl;
		number++;
		ul.unlock();
		g_cv.notify_all();
	}
}

int main() {
	thread th_even(printEven);
	thread th_odd(printOdd);
	th_even.join();
	th_odd.join();
	cout << __func__ << " : " << this_thread::get_id() << " Done!" << endl;
	return 0;
}