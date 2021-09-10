#include <iostream>
#include <future>
#include <functional>
#include <cmath>

int foo(int x, int y) {
    return std::pow(x, y);
}

void task_lambda() {
    std::packaged_task<int(int, int)> task([](int x, int y) {
        return std::pow(x, y);
    });
    
    std::future<int> result = task.get_future();
    
    task(2, 9);
    std::cout << "lambda result = " << result.get() << std::endl;
}

void task_bind() {
    std::packaged_task<int(int, int)> task(std::bind(foo, 2, 11));
    
    std::future<int> result = task.get_future();
    
    task(2, 9);
    std::cout << "bind result = " << result.get() << std::endl;
}

void task_thread() {
    std::packaged_task<int(int, int)> task(foo);
    
    std::future<int> result = task.get_future();
    std::thread task_td(std::move(task), 2, 10);
    task_td.join();
    std::cout << "thread result = " << result.get() << std::endl;
}


int main(int argc, char const *argv[])
{
    task_lambda();
    task_bind();
    task_thread();
    return 0;
}
