//
// Created by 钟卓凡 on 13/03/2023.
//
#include "confs/parser.h"
#include <toml.hpp>

int main() {
    auto a = confs_manager((std::string &) "./confs.toml");
}