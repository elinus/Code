#include <iostream>

template <typename T>
class SharedPtr {
	T* ptr;
	uint32_t* ref_count;
public:
	SharedPtr(T* ptr = nullptr) : ptr{ ptr } {
		if (ptr) {
			ref_count = new uint32_t(1);
		}
		else {
			ref_count = nullptr;
		}
	}
	~SharedPtr() {
		if (ref_count != nullptr) {
			(*ref_count)--;
			if ((*ref_count) == 0) {
				delete ptr;
				delete ref_count;
			}
		}
	}
	SharedPtr(const SharedPtr& other) {
		ptr = other.ptr;
		ref_count = other.ref_count;
		(*ref_count)++;
	}
	SharedPtr(SharedPtr&& other) {
		ptr = other.ptr;
		ref_count = other.ref_count;
		other.ptr = nullptr;
		other.ref_count = nullptr;
	}
	SharedPtr& operator=(const SharedPtr& other) {
		ptr = other.ptr;
		ref_count = other.ref_count;
		(*ref_count)++;
		return *this;
	}
	SharedPtr& operator=(SharedPtr&& other) {
		if (&other == this) return *this;
		delete ptr;
		delete ref_count;
		ptr = other.ptr;
		ref_count = other.ref_count;
		other.ptr = nullptr;
		other.ref_count = nullptr;
		return *this;
	}
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
};

//int main() {
//	std::cout << "Hello World!\n";
//	return 0;
//}