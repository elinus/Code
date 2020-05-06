#include <iostream>
#include <sstream>
#include <thread>
#include <functional>
#include "ConcurrentQueue.h"

const int number_of_consumers = 4;
const int number_of_item_to_consume = 3;
const int number_of_produce_item = number_of_item_to_consume * number_of_consumers;

void print(const std::string& x) {
    static std::mutex s_mutex;
    std::unique_lock<std::mutex> locker(s_mutex);
    std::cout << x << "\n";
}


void Producer(ConcurrentQueue<int>& q) {
    for (int i = 1; i <= number_of_produce_item; ++i) {
        std::ostringstream tmp;
        tmp << "producer :: " << i;
        print(tmp.str());
        q.push(i);
    }
}

void Consumer(ConcurrentQueue<int>& q, unsigned int id) {
    for (int i = 0; i < number_of_item_to_consume; ++i) {
        auto item = q.pop();
        std::ostringstream tmp;
        tmp << "\tconsumer(" << id << ") :: " << item;
        print(tmp.str());
    }
}

int main (int argc, char *argv[]) {
    ConcurrentQueue<int> q;

    std::thread prod(std::bind(Producer, std::ref(q)));

    std::vector<std::thread> consumers;
    for (int i = 0 ; i < number_of_consumers ; ++i) {
        std::thread consumer(std::bind(&Consumer, std::ref(q), i + 1));
        consumers.push_back(std::move(consumer));
    }

    prod.join();

    for (auto& consumer: consumers) {
        consumer.join();
    }

}
