//
// Created by 钟卓凡 on 11/02/2023.
//

#ifndef DB_BLOCKS_SSTABLE_H
#define DB_BLOCKS_SSTABLE_H

#include <iostream>
#include <array>


class sstable {
public:
    sstable();

    std::array<std::byte, 1024 * 64> store{};
    std::byte *p;

    /*
     * Write into store, return true if success else false
     * */
    template<typename T>
    bool Write(T &&a) {
        auto size = sizeof a;
        // not enough space to write
        if (this->p + size >= this->store.end()) {
            this->flush();
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
        return true;
    };

    bool flush() const;

};

#endif //DB_BLOCKS_SSTABLE_H
