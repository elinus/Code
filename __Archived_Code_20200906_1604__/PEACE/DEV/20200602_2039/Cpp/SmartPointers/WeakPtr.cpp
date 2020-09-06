#include <iostream>
#include <memory>

std::weak_ptr<int> g_w;

void observe() {
    std::cout << "use_count == " << g_w.use_count() << ": ";
    std::shared_ptr<int> p = g_w.lock();
    if (p) {
        std::cout << *p << "\n";
    } else {
        std::cout << "g_w is expired\n";
    }
}

int main (int argc, const char *argv[]) {
    {
        auto p = std::make_shared<int>(14);
        g_w = p;
        std::cout << "use_count in main == " << p.use_count() << "\n";
        observe();
    }
    observe();
    return 0;
}

