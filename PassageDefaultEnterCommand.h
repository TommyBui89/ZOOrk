//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef PASSAGEDEFAULTENTERCOMMAND_H
#define PASSAGEDEFAULTENTERCOMMAND_H

#include "Command.h"
#include "Location.h"
#include "Player.h"
#include <memory>

class Passage; // Forward declaration

class PassageDefaultEnterCommand : public Command {
public:
    PassageDefaultEnterCommand(Passage* p) : Command(nullptr), passage(p) {}

    void execute() override;

private:
    Location* location;
    Player* player;
//    std::shared_ptr<Passage> passage;
    Passage* passage;
};

#endif // PASSAGEDEFAULTENTERCOMMAND_H
