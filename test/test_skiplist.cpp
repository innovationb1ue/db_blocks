//
// Created by 钟卓凡 on 04/04/2023.
//
#include "data_structure/skiplist.h"
#include <string>

void test_skiplist_insert() {
    auto db = SkipList<std::string, std::string>(6);
    db.insert_element("123", "456");
    db.insert_element("444", "456");
    db.insert_element("11gg", "456");
    db.insert_element("abc", "1231231231323");
}

int main() {
    test_skiplist_insert();
}

