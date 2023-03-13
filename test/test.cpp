//
// Created by 钟卓凡 on 11/02/2023.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Printer { // generic functor
    std::ostream &os;

    Printer(std::ostream &os) : os(os) {}

    template<typename T>
    void operator()(const T &obj) { os << obj << ' '; } // member template

    template<typename T>
    void call(T a) {
        std::cout << a << std::endl;
    }
};

int main() {
    std::vector<int> v = {1, 2, 3};
    std::for_each(v.begin(), v.end(), Printer(std::cout));
    std::string s{"abc"};
    auto t = Printer{std::cout};
    t.call(5);
}
