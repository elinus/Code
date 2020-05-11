#include <iostream>
#include <thread>
#include <string>

void foo(int i, std::string str) {
    std::cout << std::this_thread::get_id() << " :: " << i << ", " << str << "\n";
}

void bar(int &i) {
    std::cout << std::this_thread::get_id() << " :: (inside bar) " << i << "\n";
    i = 14;
}

class Coco {
    public:
    Coco() = default;
    Coco(const Coco & other) = default;
    void zaki(int i) {
        std::cout << "Coco :: zaki = " << i << std::endl;
    }
};

int main(int argc, char const *argv[]) {
    int i = 11;
    std::string str = "elinus";
    std::thread t_foo_ { foo, i, str };
    t_foo_.join();
    std::thread t_bar_ { bar, std::ref(i) };
    t_bar_.join();
    std::cout << "(main after thread return) :: " << i << std::endl; 

    Coco coco_obj;
    std::thread t_coco_ { &Coco::zaki, &coco_obj, 11 };
    t_coco_.join();
    return 0;
}
