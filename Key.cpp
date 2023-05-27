//
// Created by Tommy Bui on 27/5/2023.
//

#include "Key.h"

Key::Key(const std::string& n, const std::string& d) : Item(n, d) {}

void Key::use(Room* room) {
    if (room->isSecretRoom()) {
        std::shared_ptr<Passage> secretPassage = room->getPassage("unlock");
        if (secretPassage) {
            if (secretPassage->isLocked()) {
                secretPassage->unlock();
                std::cout << "You use the key to unlock the secret room passage!" << std::endl;
            } else {
                std::cout << "The secret room passage is already unlocked." << std::endl;
            }
        } else {
            std::cout << "There is no secret room passage in this room." << std::endl;
        }
    } else {
        std::cout << "The key doesn't seem to work here." << std::endl;
    }
}


