#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

void do_something(unsigned i){}

struct coco {
    int &i;
    coco(int& i_)
        : i(i_)
    {}
    void operator()() {
        std::cout << "operator() :: tid = " << std::this_thread::get_id() << "\n";
        for (unsigned i = 0; i < 1000000; ++i) {
            do_something(i);
        }
    }
};

class thread_guard {
    private:
        std::thread& t;
    public:
        explicit thread_guard(std::thread& t_)
            : t(t_)
        {
            std::cout << "tg :: tid = " << std::this_thread::get_id() << "\n";
        }
        ~thread_guard() {
            std::cout << "~tg :: tid = " << std::this_thread::get_id() << "\n";
            if (t.joinable()) {
                t.join();
            }
        }
        thread_guard(const thread_guard&) = delete;
        thread_guard& operator =(const thread_guard&) = delete; 
};

class scoped_thread {
    private:
        std::thread t;
    public:
        explicit scoped_thread(std::thread t_)
            : t(std::move(t_))
        {
            std::cout << "st :: tid = " << t.get_id() << "\n";
            if (!t.joinable()) {
                throw std::logic_error("No thread");
            }
        }
        scoped_thread() {
            std::cout << "~st :: tid = " << t.get_id() << "\n";
            t.join();
        }
        scoped_thread(const scoped_thread&) = delete;
        scoped_thread& operator =(const scoped_thread&) = delete; 
};

void zaki() {
    int local_state = 0;
    coco coco_(local_state);
    std::thread t(coco_);
    thread_guard tg(t); 
    
    scoped_thread st(std::thread(coco_));
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    
    std::cout << "tid=" << std::this_thread::get_id() << ", doing some work with zaki..\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main (int argc, const char *argv[]) {
    zaki();
    std::cout << "All threads joined. Exiting main=" << std::this_thread::get_id() << "\n";
    return 0;
}

