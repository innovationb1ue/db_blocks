#include <iostream>
#include "sstable.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto s = sstable();
    int a[]{1, 2, 3, 4, 5};
    auto flag = s.Write(std::string{"cpp"});
    if (flag) {
        std::cout << "Write success" << std::endl;
    }
    return 0;
}
