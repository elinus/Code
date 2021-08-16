#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>

void initializer(std::promise<std::string>* promise_obj) {
	std::cout << "Inside thread = " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "Promise set - start {{==>>" << std::endl;
	promise_obj->set_value("coco-zaki");
	std::cout << "Promise set - end <<==}}" << std::endl;
}

//int main() {
//	std::promise<std::string> promise_obj;
//	std::future<std::string> future_obj = promise_obj.get_future();
//	std::thread th_{ initializer, &promise_obj };
//	std::cout << "main = " << std::this_thread::get_id() << " waiting..";
//	std::cout << "main = " << std::this_thread::get_id() << " , future(cat) = " << future_obj.get();
//	th_.join();
//}