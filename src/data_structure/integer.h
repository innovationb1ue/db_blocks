//
// Created by 钟卓凡 on 19/02/2023.
//

#ifndef DB_BLOCKS_INTEGER_H
#define DB_BLOCKS_INTEGER_H

#include "namespace.h"
#include "data.h"

namespace DB_BLOCKS_NAMESPACE {

    class Integer : public data<int, int> {
    public:
        Integer(unsigned long id, int k, int v) : data<int, int>(id, k, v) {
        };

        std::byte to_bytes() override {
            return std::byte(1);
        }
    };
}

#endif //DB_BLOCKS_INTEGER_H
