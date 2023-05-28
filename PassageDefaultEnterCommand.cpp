//
// Created by Richard Skarbez on 5/7/23.
//

#include "PassageDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"

//void PassageDefaultEnterCommand::execute() {
//    Player* player = Player::instance();
//    if (passage->isLocked()) {
//        std::shared_ptr<Item> requiredItem = passage->getRequiredItem();
//        if (requiredItem && !player->hasItem(requiredItem->getName())) {
//            std::cout << "You need a " << requiredItem->getName() << " to go that way.\n";
//            return;
//        }
//        passage->unlock();
//        std::cout << "You unlocked the passage.\n";
//    }
//    player->setCurrentRoom(passage->getTo());
//    std::cout << "You entered the " << passage->getTo()->getName() << ".\n";
//}

void PassageDefaultEnterCommand::execute() {
    Player* player = Player::instance();
    if (passage->isLocked()) {
        std::shared_ptr<Item> requiredItem = passage->getRequiredItem();
        if (requiredItem && !player->hasItem(requiredItem->getName())) {
            std::cout << "You need a " << requiredItem->getName() << " to go that way.\n";
            return;
        }
        passage->unlock();
//        std::cout << "You unlocked the passage.\n";
    }
    player->setCurrentRoom(passage->getTo());
    std::cout << "You entered the " << passage->getTo()->getName() << ".\n";
}