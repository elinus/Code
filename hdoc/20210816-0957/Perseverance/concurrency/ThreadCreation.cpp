#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

void foo() {
	std::cout << std::this_thread::get_id() << " ::inside foo" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << std::this_thread::get_id() << " thread exiting.." << std::endl;
}

struct Buzz {
	void operator()() {
		std::cout << std::this_thread::get_id() << " ::inside foo" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		std::cout << std::this_thread::get_id() << " thread exiting.." << std::endl;
	}
};

void bar() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "bar, thread-id = " << std::this_thread::get_id() << std::endl;
}

//int main() {
//	std::cout << "main-thread :: " << std::this_thread::get_id() << std::endl;
//	
//	std::function<void()> lambda_foo = []() {
//		std::cout << std::this_thread::get_id() << " ::inside foo" << std::endl;
//		std::this_thread::sleep_for(std::chrono::milliseconds(1100));
//		std::cout << std::this_thread::get_id() << " thread exiting.." << std::endl;
//
//	};
//
//	std::thread th_foo(foo);
//	std::thread th_func_obj{ Buzz() };
//	std::thread th_lambda(lambda_foo);
//	
//	th_foo.join();
//	th_func_obj.join();
//	th_lambda.join();
//
//	std::thread th_bar(bar);
//	if (th_bar.joinable()) th_bar.detach();
//
//	// waiting for detached thread print
//	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//
//	std::cout << "exiting main-thread :: " << std::this_thread::get_id() << std::endl;
// 	return 0;
//}