//
// Created by Tommy Bui on 27/5/2023.
//

#ifndef ZOORK_FRIENDLYNPCINTERACTCOMMAND_H
#define ZOORK_FRIENDLYNPCINTERACTCOMMAND_H

#include "Command.h"

class FriendlyNPCInteractCommand : public Command {
public:
    FriendlyNPCInteractCommand(GameObject* g) : Command(g) {} // Constructor accepting GameObject*

    void execute() override {
        std::cout << "Friendly NPC: " << "Thank you for interacting with me! How can I assist you?" << std::endl;
    }
};

#endif //ZOORK_FRIENDLYNPCINTERACTCOMMAND_H
