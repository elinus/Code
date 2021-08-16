#include <iostream>
using namespace std;

template <typename T>
class auto_ptr3 {
	T* ptr;
public:
	auto_ptr3(T* ptr = nullptr) : ptr{ ptr }
	{
		cout << "obj = " << this << endl;
	}
	~auto_ptr3() {
		cout << "~obj = " << this << endl;
		delete ptr;
	}
	auto_ptr3(const auto_ptr3& other) {
		cout << "obj(copy ctor) = " << this << endl;
		ptr = new T;
		*ptr = *(other.ptr);
	}
	auto_ptr3& operator=(const auto_ptr3& other) {
		if (&other != this) {
			cout << "obj(assignment opr.) = " << this << endl;
			delete ptr;
			ptr = new T;
			*ptr = *(other.ptr);
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

auto_ptr3<Resource> generateResource() {
	auto_ptr3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}


//int main() {
//	//auto_ptr3<Resource> res1{ new Resource() };
//	//auto_ptr3<Resource> res2{ res1 };
//	auto_ptr3<Resource> mainres;
//	cout << "-----" << endl;
//	mainres = generateResource(); // this assignment will invoke the copy assignment
//	cout << "-----" << endl;
//	return 0;
//}