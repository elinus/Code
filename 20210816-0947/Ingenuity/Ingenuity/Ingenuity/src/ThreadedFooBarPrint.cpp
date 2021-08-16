#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <functional>

class FooBar {
private:
	int n;
	std::condition_variable cv;
	std::mutex mt;
	int var = 0;
public:
	FooBar(int n) {
		this->n = n;
	}
	void foo(std::function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> l(mt);
			cv.wait(l, [this]() { return var == 0; });
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			var = 1;
			cv.notify_one();
		}
	}
	void bar(std::function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			std::unique_lock<std::mutex> l(mt);
			cv.wait(l, [this]() { return var == 1; });
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			var = 0;
			cv.notify_one();
		}
	}
};

//int main() {
//	std::function<void()> foo = []() {
//		std::cout << "Foo" << std::endl;
//	};
//	std::function<void()> bar = []() {
//		std::cout << "Bar" << std::endl;
//	};
//	FooBar fb_obj(5);
//	std::thread th_foo(&FooBar::foo, &fb_obj, foo);
//	std::thread th_bar(&FooBar::bar, &fb_obj, bar);
//	th_foo.join();
//	th_bar.join();
//	return 0;
//}