//
// Created by 钟卓凡 on 15/04/2023.
//


#ifndef DB_BLOCKS_DB_H
#define DB_BLOCKS_DB_H


#include "iostream"
#include "shared_mutex"

class db {
public:
    // global lock
    std::mutex mutex;
    std::shared_mutex mutex1;

    db() : mutex(std::mutex()), mutex1(std::shared_mutex()) {

    };

    // open a db instance
    void Open() {
        mutex1.lock();
        mutex1.unlock();
    }


    // lock the whole db
    void Lock() {

    }
};


#endif //DB_BLOCKS_DB_H
