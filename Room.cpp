//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"
#include "Room.h"

#include <utility>


Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

void Room::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}

void Room::removeItem(const std::string &itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [itemName](const std::shared_ptr<Item>& item) {
                                   return item->getName() == itemName;
                               }), items.end());
}

std::shared_ptr<Item> Room::getItem(const std::string &itemName) {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Item>> Room::getItems() const {
    return items;
}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}

//std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
//    if (passageMap.contains(direction)) {
//        return passageMap[direction];
//    } else {
//        std::cout << "It is impossible to go " << direction << "!\n";
//        return std::make_shared<NullPassage>(this);
//    }
//}

std::shared_ptr<Passage> Room::getPassage(const std::string& direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else if (isSecretRoom() && direction == "secret") {
        // Allow passage to the secret room without checking for the key
        auto secretPassage = std::make_shared<Passage>("secret-passage", "A hidden passage to the secret room.", nullptr, nullptr);
        return secretPassage;
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(nullptr);
    }
}

bool Room::isSecretRoom() const {
    return (getName() == "secret-room");
}

bool Room::playerHasKey() const {
    for (const auto& item : items) {
        if (item->getName() == "key") {
            return true;  // Player has the key item
        }
    }
    return false;  // Player does not have the key item
}