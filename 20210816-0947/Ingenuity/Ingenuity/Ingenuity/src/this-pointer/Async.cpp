#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void print_ten(char c, int ms) {
	for (int i = 0; i < 10; i++) {
		std::this_thread::sleep_for(std::chrono::microseconds(ms));
		std::cout << c;
	}
}

//int main() {
//	std::cout << "launch::async" << std::endl;
//	std::future<void> foo = std::async(std::launch::async, print_ten, '*', 14);
//	std::future<void> bar = std::async(std::launch::async, print_ten, '@', 20);
//	foo.get(); 
//	bar.get();
//
//	std::cout << "\n\n";
//
//	std::cout << "launch::deferred" << std::endl;
//	foo = std::async(std::launch::deferred, print_ten, '*', 14);
//	bar = std::async(std::launch::deferred, print_ten, '@', 20);
//	bar.get();
//	foo.get();
//
//	return 0;
//}