//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_CHARACTER_H
#define ZOORK_CHARACTER_H

#include "GameObject.h"
#include "Item.h"
#include <vector>
#include <string>
#include <memory>
#include "Location.h"
#include "Command.h"

class Character : public GameObject {
public:
    Character(const std::string &, const std::string &);

    void setInteractCommand(std::shared_ptr<Command> command);
    void interact();

    void setDialogue(const std::string& dialogue);

protected:
//    std::vector<Item*> inventory;
//    std::vector<std::string> tags;
//    int health;
//    int attack;
//    int move;
//    int initiative;

    std::shared_ptr<Command> interactCommand;
    std::string dialogue;
};

#endif //ZOORK_CHARACTER_H
