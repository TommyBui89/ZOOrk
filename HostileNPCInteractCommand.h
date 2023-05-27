//
// Created by Tommy Bui on 27/5/2023.
//

#ifndef ZOORK_HOSTILENPCINTERACTCOMMAND_H
#define ZOORK_HOSTILENPCINTERACTCOMMAND_H

#include "Command.h"

class HostileNPCInteractCommand : public Command {
public:
    HostileNPCInteractCommand(GameObject* g) : Command(g) {} // Constructor accepting GameObject*

    void execute() override {
        std::cout << "Hostile NPC: " << "Stay away! I'm not in the mood to talk." << std::endl;
    }
};

#endif //ZOORK_HOSTILENPCINTERACTCOMMAND_H
