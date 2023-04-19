//
// Created by 钟卓凡 on 16/04/2023.
//


#ifndef DB_BLOCKS_LOCK_MANAGER_H
#define DB_BLOCKS_LOCK_MANAGER_H

#include <shared_mutex>
#include <unordered_map>

// first intended to lock some most important metadata.
class lock_manager {
public:
    // global lock for this global lock manager
    std::shared_mutex mutex;

    // lock map
    std::unordered_map<std::string, std::shared_ptr<std::shared_mutex>> map;

    // delete constructor
    lock_manager(lock_manager const &) = delete;

    void operator=(lock_manager const &) = delete;

    static lock_manager &getInstance() {
        static lock_manager instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }


    // get the named lock
    // will create lock if it does not exist.
    // use this method to get the lock and emplace std::scoped_lock to manage concurrency
    std::shared_ptr<std::shared_mutex> get(std::string &name) {
        // unique lock manager
        std::unique_lock<std::shared_mutex> lock(mutex);
        if (auto item = map.find(name); item != map.end()) {
            return item->second;
        } else {
            auto mut = std::make_shared<std::shared_mutex>();
            map.insert(std::make_pair(name, mut));
            return mut;
        }
    }

    // WARNING: this could be dangerous
    // lock certain name with unique lock
    void lock(std::string &name) {
        std::unique_lock<std::shared_mutex> lock(mutex);
        auto key_lock = get(name);
        key_lock->lock();
    }

    // WARNING: this could be dangerous
    // try lock certain name with unique lock
    void try_lock(std::string &name) {
        std::unique_lock<std::shared_mutex> lock(mutex);
        auto key_lock = get(name);
        key_lock->try_lock();
    }

    // WARNING: this could be dangerous
    // unlock certain name
    void unlock(std::string &name) {
        std::unique_lock<std::shared_mutex> lock(mutex);
        auto key_lock = get(name);
        key_lock->unlock();
    }

private:
    static lock_manager instance;

    lock_manager() : mutex(std::shared_mutex()),
                     map(std::unordered_map<std::string, std::shared_ptr<std::shared_mutex>>()) {
    }
};

#endif //DB_BLOCKS_LOCK_MANAGER_H
