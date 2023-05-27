//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
}

void Player::removeItem(const std::string &itemName) {
    inventory.erase(std::remove_if(inventory.begin(), inventory.end(),
                                   [itemName](const std::shared_ptr<Item>& item) {
                                       return item->getName() == itemName;
                                   }), inventory.end());
}

std::shared_ptr<Item> Player::getItem(const std::string &itemName) {
    for (const auto& item : inventory) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Item>> Player::getInventory() const {
    return inventory;
}

void Player::go(const std::string& direction) {
    std::shared_ptr<Passage> passage = currentRoom->getPassage(direction);
}

