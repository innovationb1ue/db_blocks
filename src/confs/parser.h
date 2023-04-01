//
// Created by 钟卓凡 on 13/03/2023.
//

#ifndef DB_BLOCKS_PARSER_H
#define DB_BLOCKS_PARSER_H

#include <string>
#include <toml.hpp>
#include "iostream"

class confs_manager {
public:
    explicit confs_manager(std::string &path) : path(path) {
        auto data = toml::parse(path);
        std::cout << data << std::endl;
    };

private:
    std::string &path;
    toml::basic_value<toml::discard_comments> data;
};


#endif //DB_BLOCKS_PARSER_H
