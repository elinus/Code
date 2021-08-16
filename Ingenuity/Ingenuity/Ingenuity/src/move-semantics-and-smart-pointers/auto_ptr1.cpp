#include <iostream>
using namespace std;

template <typename T>
class auto_ptr1 {
	T* ptr;
public:
	auto_ptr1(T *ptr = nullptr): ptr{ ptr }
	{}
	~auto_ptr1() {
		if (ptr) delete ptr;
	}
	T& operator*() const {
		return *ptr;
	}
	T* operator->() const {
		return ptr;
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
//	auto_ptr1<Resource> res1{ new Resource() };
//	auto_ptr1<Resource> res2{ res1 }; // crash
//	return 0;
//}