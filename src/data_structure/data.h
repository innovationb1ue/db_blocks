//
// Created by 钟卓凡 on 19/02/2023.
//

#include <string>

#ifndef DB_BLOCKS_DATA_H
#define DB_BLOCKS_DATA_H


template<typename K, typename V>
class data {
public:
    data(unsigned long id, K k, V v) : _id(id), _K(k), _V(v) {}

    // take how much byte to store this data
    virtual size_t space() {
        return sizeof(_K) + sizeof(_V);
    }

    virtual std::byte to_bytes();

private:
    unsigned long _id;
    K _K;
    V _V;
};


#endif //DB_BLOCKS_DATA_H
