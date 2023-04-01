//
// Created by 钟卓凡 on 19/02/2023.
//
#include <utility>

#include "data.h"


#ifndef DB_BLOCKS_SLICE_STRUCT_H
#define DB_BLOCKS_SLICE_STRUCT_H


class slice_struct : data<std::string, std::string> {
public:
    slice_struct(unsigned long id, std::string k, std::string v) : data(id, std::move(k), std::move(v)) {

    }

    size_t space() {
        return 2 * sizeof(std::string);
    }

private:
    unsigned long _id;
    std::string _K;
    std::string _V;

};


#endif //DB_BLOCKS_SLICE_STRUCT_H
