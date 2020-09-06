#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <functional>

void coco(int i, std::string & s) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "tid=" << std::this_thread::get_id() << " :: i = " << i
        << ", s = " << s << "\n";
    s = "__el!nus__";
}

void zaki(int i, const std::string & s) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "tid=" << std::this_thread::get_id() << " :: i = " << i
        << ", s = " << s << "\n";
}

struct Coco {
    void zaki(int i, const std::string & s) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "tid=" << std::this_thread::get_id() << " :: i = " << i
            << ", s = " << s << "\n";
    }
};


int main (int argc, const char *argv[]) {
    char buffer[1024];
    sprintf(buffer, "%s", "__elinus__");
   
    std::string eli_ { "__elinus__" } ;

    std::thread t1(zaki, 14, buffer);
    std::thread t2(coco, 14, std::ref(eli_));

    Coco coco_;
    std::thread t3(&Coco::zaki, &coco_, 14, buffer);
    
    t1.join();
    t2.join();
    t3.join();

    std::cout << "eli_ :: " << eli_ << "\n";
    
    std::cout << "All threads joined. Exiting main=" << std::this_thread::get_id() << "\n";
    return 0;
}

