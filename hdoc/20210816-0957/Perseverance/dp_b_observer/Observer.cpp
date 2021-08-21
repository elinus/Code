#include <iostream>
#include <string>
#include <list>
#include <memory>

struct IObserver {
	virtual ~IObserver() {}
	virtual void update(const std::string& msg_from_subject) = 0;
};

struct ISubject {
	virtual ~ISubject() {}
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;
};

struct Subject : ISubject {
	virtual ~Subject() {
		std::cout << "Goodbye, I was the subject!" << std::endl;
	}
	// Inherited via ISubject
	virtual void attach(IObserver* observer) override
	{
		list_observer_.push_back(observer);
	}
	virtual void detach(IObserver* observer) override
	{
		list_observer_.remove(observer);
	}
	virtual void notify() override
	{
		auto iterator = list_observer_.begin();
		how_many_observer();
		while (iterator != list_observer_.end()) {
			(*iterator)->update(message_);
			iterator++;
		}
	}

	void create_message(const std::string& message = "Empty") {
		this->message_ = message;
		notify();
	}
	
	void how_many_observer() {
		std::cout << "There are " << list_observer_.size() << " observers in the list" << std::endl;
	}

	void some_business_logic() {
		this->message_ = "change message [[ message ]]";
		notify();
		std::cout << "I'm about to do some thing important" << std::endl;
	}
private:
	std::list<IObserver*> list_observer_;
	std::string message_;
};

struct Observer : IObserver {

	Observer(ISubject& subject) : subject_{subject}
	{
		this->subject_.attach(this);
		std::cout << "Hi, I'm the Observer \"" << ++static_number_ << "\".\n";
		this->number_ = static_number_;
	}

	virtual ~Observer() {
		std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
	}

	// Inherited via IObserver
	virtual void update(const std::string& msg_from_subject) override
	{
		this->message_from_subject_ = msg_from_subject;
		print_info();
	}

	void remove_me_from_the_list() {
		subject_.detach(this);
		std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
	}
	void print_info() {
		std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
	}
private:
	std::string message_from_subject_;
	ISubject& subject_;
	static int static_number_;
	int number_;
};

int Observer::static_number_ = 0;

int main() {
	std::unique_ptr<Subject> subject = std::make_unique<Subject>();
	std::unique_ptr<Observer> observer1 = std::make_unique<Observer>(*subject);
	std::unique_ptr<Observer> observer2 = std::make_unique<Observer>(*subject);
	std::unique_ptr<Observer> observer3 = std::make_unique<Observer>(*subject);
	std::unique_ptr<Observer> observer4;
	std::unique_ptr<Observer> observer5;

	subject->create_message("Hello World!");
	observer3->remove_me_from_the_list();

	subject->create_message("The weather is hot today! :p");
	observer4 = std::make_unique<Observer>(*subject);

	observer2->remove_me_from_the_list();
	observer5 = std::make_unique<Observer>(*subject);

	subject->create_message("My new car is great! ;)");
	observer5->remove_me_from_the_list();

	observer4->remove_me_from_the_list();
	observer1->remove_me_from_the_list();

	return 0;
}
