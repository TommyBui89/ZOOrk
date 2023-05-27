//
// Created by Tommy Bui on 27/5/2023.
//
#include "Door.h"

Door::Door(const std::string& n, const std::string& d, Room* from, Room* to, std::shared_ptr<Item> item)
        : Passage(n, d, from, to), requiredItem(std::move(item)) {}

bool Door::isLocked() const {
    return locked;
}

void Door::unlock(const std::shared_ptr<Item> &item) {
    if (item == requiredItem) {
        locked = false;
    }
}