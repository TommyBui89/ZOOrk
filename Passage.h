//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_PASSAGE_H
#define ZOORK_PASSAGE_H

//#include "Room.h"
//#include <iostream>

#include <string>
#include <memory>
#include "Command.h"
#include "Location.h"
#include "Item.h"

class Room;

class Passage : public Location {
public:
    static void createBasicPassage(Room* from, Room* to, const std::string& direction, bool bidirectional = true);

    Passage(const std::string& n, const std::string& d, Room* from, Room* to);
    Passage(const std::string& n, const std::string& d, std::shared_ptr<Command> c, Room* from, Room* to);

    void setFrom(Room* r);
    Room* getFrom() const;

    void setTo(Room* r);
    Room* getTo() const;

    bool isLocked() const;
    void unlock();

    std::shared_ptr<Item> getRequiredItem() const;
    void setRequiredItem(std::shared_ptr<Item> item);

protected:
    static std::string oppositeDirection(const std::string &);

    Room* fromRoom;
    Room* toRoom;

    bool locked = true;
    std::shared_ptr<Item> requiredItem;
};

#endif //ZOORK_PASSAGE_H
