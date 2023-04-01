//
// Created by 钟卓凡 on 14/02/2023.
//

#ifndef DB_BLOCKS_MEMPAGE_H
#define DB_BLOCKS_MEMPAGE_H

#include <memory>
#include <cstdlib>
#include <iostream>
#include <array>

class mem_page {
public:

    template<typename T>
    bool Write(T &&a) {
        auto size = sizeof a;
        // not enough space to write
        if (this->p + size >= this->store.end()) {
            return false;
        }
        // test start
        // transform data into bytes and write into this->p
        std::transform(std::begin(a), std::end(a), this->p, [](char c) {
            std::cout << c << 1;
            return std::byte(c);
        });
        std::cout << std::endl;
        std::cout << this->p << " " << this->store.end() << std::endl;
        std::cout << (char *) (this->p) << std::endl;
        std::cout << "in specialized " << &a << " val = " << a << " size = " << size << std::endl;

        this->p += size;
    }

private:
    std::unique_ptr<void> page;
    std::byte *p = static_cast<std::byte *>(this->page.get());
    std::array<std::byte, 65536> store;

};


#endif //DB_BLOCKS_MEMPAGE_H
