//
// Created by Tommy Bui on 27/5/2023.
//

#include "Key.h"
#include "Door.h"

Key::Key(const std::string& n, const std::string& d) : Item(n, d) {}

void Key::use(Room* room) {
    // Check if the room has a secret door passage
    std::shared_ptr<Door> secretDoor = std::dynamic_pointer_cast<Door>(room->getPassage("west"));
    if (secretDoor) {
        if (secretDoor->isLocked()) {
            secretDoor->unlock();
            std::cout << "You use the key to unlock the secret door!" << std::endl;
        } else {
            std::cout << "The secret door is already unlocked." << std::endl;
        }
    } else {
        std::cout << "There is no secret door in this room." << std::endl;
    }
}