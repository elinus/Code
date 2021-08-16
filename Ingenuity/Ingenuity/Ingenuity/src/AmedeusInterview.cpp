#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
	Base() {
		cout << __func__ << endl;
	}
	~Base() {
		cout << __func__ << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << __func__ << endl;
	}
	~Derived() {
		cout << __func__ << endl;
	}
};

//int main() {
//	//Base* b_obj = new Derived();
//	//delete b_obj;
//	shared_ptr<Base> sb = shared_ptr<Derived>(new Derived());
//	return 0;
//}