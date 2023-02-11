//
// Created by 钟卓凡 on 11/02/2023.
//

#include "sstable.h"
#include <array>
#include <cstddef>
#include <iostream>


sstable::sstable() :
        store(std::array<std::byte, 65536>{}), p(store.begin()) {

}

bool sstable::flush() const {
    this->store.cbegin();
    return false;
}








