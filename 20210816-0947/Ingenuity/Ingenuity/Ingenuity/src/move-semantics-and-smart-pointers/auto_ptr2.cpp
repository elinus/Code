#include <iostream>
using namespace std;

template <typename T>
class auto_ptr2 {
	T* ptr;
public:
	auto_ptr2(T* ptr = nullptr) : ptr{ ptr }
	{}
	~auto_ptr2() {
		if (ptr) delete ptr;
	}
	auto_ptr2(auto_ptr2& other) {
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	auto_ptr2& operator=(auto_ptr2& other) {
		if (&other != this) {
			delete ptr;
			ptr = other.ptr;
			other.ptr = nullptr;
		}
		return *this;
	}
	T& operator*() const {
		return *ptr;
	}
	T* operator->() const {
		return ptr;
	}
	bool is_null() const {
		return ptr == nullptr;
	}
};

struct Resource {
	Resource() {
		//cout << __FILE__ << " :: LNo= " << __LINE__ << " :: " << __func__ << endl;
		std::cout << "Resource acquired\n";
	}
	~Resource() {
		//cout << __FILE__ << " :: LNo= " << __LINE__ << " :: " << __func__ << endl;
		std::cout << "Resource destroyed\n";
	}
	void say_hi() {
		cout << "Hi!\n";
	}
};

//int main() {
//	auto_ptr2<Resource> res1{ new Resource() };
//	auto_ptr2<Resource> res2{ res1 };
//	return 0;
//}