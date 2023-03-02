#include <iostream>
#include "sstable/sstable.hpp"
#include "data_structure/slice_struct.h"
#include <filesystem>
#include <map>
#include <spdlog/spdlog.h>

int main() {
    std::cout << "Current path = " << std::filesystem::current_path() << std::endl;
    auto s = dbblocksnamespace::sstable("./test_table.txt");
    int a[]{1, 2, 3, 4, 5};

    auto kvstore = std::map<std::string, std::string>{{"123", "456"},
                                                      {"444", "666"}};
    auto flag = s.Write(kvstore);
    if (flag) {
        std::cout << "Write success" << std::endl;
    }
    spdlog::info("hi hi logger");

    return 0;
}

