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

bool Player::hasItem(const std::string &itemName) {
    return getItem(itemName) != nullptr;
}

std::vector<std::shared_ptr<Item>> Player::getInventory() const {
    return inventory;
}

void Player::go(const std::string& direction, const std::string& requiredItem) {
    std::shared_ptr<Passage> passage = currentRoom->getPassage(direction);

    if (passage != nullptr) {
        // Check if the passage requires the player to have the required item
        if (passage->getRequiredItem() != nullptr && passage->getRequiredItem()->getName() == requiredItem) {
            std::shared_ptr<Item> item = getItem(requiredItem);
            if (item) {
                // Remove the required item from the player's inventory
                removeItem(requiredItem);

                // Move the player to the next room
                passage->enter();
            } else {
                std::cout << "You need a " << requiredItem << " to go that way.\n";
            }
        } else {
            // If the passage doesn't require an item, move the player to the next room
            passage->enter();
        }
    } else {
        std::cout << "You can't go that way.\n";
    }
}

void Passage::setRequiredItem(std::shared_ptr<Item> item) {
    requiredItem = std::move(item);
}


