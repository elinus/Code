#include <iostream>
#include <thread>
#include <future>
#include <numeric>
#include <vector>
#include <exception>

void accumulate(std::vector<int>::iterator first, std::vector<int>::iterator last, std::promise<int> accumulate_promise) 
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);
}

int main(int argc, char const *argv[])
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(), std::move(accumulate_promise));
    accumulate_future.wait();
    std::cout << "result = " << accumulate_future.get() << std::endl;
    work_thread.join();

    
    std::promise<int> result;
    std::thread t([&]{
        try {
            throw std::runtime_error("test-exception!");
        } catch(...) {
            try {
                result.set_exception(std::current_exception());
            } catch(...){}
        }
        
    });

    try {
        std::cout << result.get_future().get() << std::endl;
    } catch (const std::exception e) {
        std::cout << "Exception from thread :: " << e.what() << std::endl;
    }
    t.join();

    return 0;
}
