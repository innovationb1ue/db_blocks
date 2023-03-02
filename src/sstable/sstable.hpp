//
// Created by 钟卓凡 on 11/02/2023.
//

#ifndef DB_BLOCKS_SSTABLE_H
#define DB_BLOCKS_SSTABLE_H

#include <iostream>
#include <array>
#include "namespace.h"
#include <cstdlib>
#include <memory>
#include <fstream>
#include <map>
#include "data_structure/data.h"
#include <spdlog/spdlog.h>

#pragma once

namespace DB_BLOCKS_NAMESPACE {
    class sstable {
    public:
        sstable(const std::string &path) {
            //  should not overwrite sstable file
            if (std::filesystem::exists(path)) {
                this->is_ready = false;
                spdlog::warn("repeated path in sstable");
                return;
            };
            // open file output stream
            this->_f = std::ofstream(path, std::ios::out);
            this->is_ready = true;
            spdlog::info("construct sstable success");
        };

        /*
         * Write into store, return true if success else false
         * It's caller's duty to maintain the write order of this table.
         * */
        template<typename K, typename V>
        bool Write(std::map<K, V> &map) {
            if (!this->is_ready) {
            }
            // check available space
            auto k_size = sizeof(K);
            auto v_size = sizeof(V);
            if (this->_cur_size + k_size + v_size > this->_max_size) {
                this->is_ready = false;
                return false;
            }
            // write into file
            for (const auto &[key, value]: map) {
                this->_f << key << value;
                this->_f.close();
                std::cout << key << ":" << value << std::endl;
            }
            this->_cur_size += (k_size + v_size);
            return true;
        };

        template<typename K, typename V>
        bool Write(data<K, V> d) {
            if (this->_cur_size + d->space() > this->_max_size) {
                this->is_ready = false;
                return false;
            }
            std::cout << (int *) d->to_bytes() << std::endl;
            this->_cur_size += d->space();
            return true;
        }

        void Compact();


    private:
        // file handle for private use
        std::ofstream _f;
        // this mark this SStable is ready for writing or not.
        bool is_ready;
        size_t _cur_size = 0;
        size_t _max_size = 65536;
    };

#endif //DB_BLOCKS_SSTABLE_H

}
