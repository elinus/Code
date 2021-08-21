#include <iostream>

class Subject {
public:
	virtual void request() = 0;
};

class RealSubject : public Subject {
public:
	void request() override {
		std::cout << "RealSubject: Handling request!" << std::endl;
	}
};

class Proxy : public Subject {
private:
	RealSubject* real_subject_;
	bool check_access() const {
		std::cout << "Proxy: checking access prior firing a real request.\n";
		return true;
	}
	void log_access() const {
		std::cout << "Proxy: logging the time of access.\n";
	}
public:
	Proxy(RealSubject* real_subject) : real_subject_{new RealSubject(*real_subject)} 
	{}
	~Proxy() {
		delete real_subject_;
	}
	void request() override {
		if (this->check_access()) {
			this->real_subject_->request();
			this->log_access();
		}
	}
};

void ClientCode(Subject& subject) {
	subject.request();
}

//int main() {
//	std::cout << "Client: Executing the client code with a real subject:\n";
//	RealSubject* real_subject = new RealSubject;
//	ClientCode(*real_subject);
//	std::cout << "\n";
//	std::cout << "Client: Executing the same client code with a proxy:\n";
//	Proxy* proxy = new Proxy(real_subject);
//	ClientCode(*proxy);
//	delete real_subject;
//	delete proxy;
//	return 0;
//}