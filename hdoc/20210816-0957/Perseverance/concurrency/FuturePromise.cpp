#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void initializer(std::promise<int>* promise_obj) {
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << std::this_thread::get_id() << " thread is settign value now\n";
	promise_obj->set_value(20);
}

int main() {
	std::promise<int> promise_obj;
	std::future<int> future_obj = promise_obj.get_future();
	std::thread th_(initializer, &promise_obj);
	std::cout << "got object in future = " << future_obj.get() << std::endl; // blocking call
	th_.join();
	return 0;
}