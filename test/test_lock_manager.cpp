//
// Created by 钟卓凡 on 16/04/2023.
//
#include "concurrency/lock_manager.h"
#include "shared_mutex"
#include "stack"
#include "vector"
#include "thread"
#include "iostream"


int main() {
    auto stack = std::vector<std::string>();
    auto lock = lock_manager::getInstance().get((std::string &) "ggbob");

    auto incr = 0;

    auto push = [&]() {
        std::scoped_lock<std::shared_mutex> lock1(*lock);
        auto max = incr + 10;
        for (auto i = incr; i < max; i++) {
            stack.push_back(std::to_string(i));
            incr++;
        }
    };


    std::thread t1(push);
    std::thread t2(push);

    t1.join();
    t2.join();

    int count = 0;
    std::cout << stack.size() << std::endl;

    for (auto &idx: stack) {
        // nums should be in order since we locked the funcs up
        std::cout << idx << "  " << std::to_string(count) << std::endl;
        assert(idx == std::to_string(count));
        count++;
    }

}