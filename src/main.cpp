#include <iostream>
#include <filesystem>
#include <map>
#include <spdlog/spdlog.h>

int main() {
    auto kvstore = std::map<std::string, std::string>{{"123", "456"},
                                                      {"444", "666"}};

    spdlog::info("hi hi logger");

    return 0;
}

