//
// Created by Richard Skarbez on 5/7/23.
//

#include "Character.h"
#include <iostream>

//Character::Character(const std::string &n, const std::string &d) : GameObject(n, d) {}

Character::Character(const std::string &name, const std::string &description)
        : GameObject(name, description) {}

void Character::setInteractCommand(std::shared_ptr<Command> command) {
    interactCommand = std::move(command);
}

void Character::interact() {
    if (interactCommand) {
        interactCommand->execute();
    }
}

void Character::setDialogue(const std::string& dialogue) {
    this->dialogue = dialogue;
}

//void Character::interact() {
//    if (interactCommand) {
//        interactCommand->execute();
//    } else {
//        std::cout << "There is nothing to interact with.\n";
//    }
//}
