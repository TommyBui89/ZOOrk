//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Location.h"
#include <map>

#include <vector>
#include "Command.h"
//#include "Passage.h"
#include "NullPassage.h"
#include <string>
#include <memory>
#include "Item.h"
#include <unordered_map>

class Passage;

class Room : public Location {
public:
    Room(const std::string &, const std::string &);

    Room(const std::string &, const std::string &, std::shared_ptr<Command>);

    void addItem(std::shared_ptr<Item> item);

    void removeItem(const std::string& itemName);

    std::shared_ptr<Item> getItem(const std::string& itemName);

    std::vector<std::shared_ptr<Item>> getItems() const;

//    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void addPassage(const std::string& direction, std::shared_ptr<Passage> p);

//    void removePassage(const std::string &);
    void removePassage(const std::string& direction);

//    std::shared_ptr<Passage> getPassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string& direction);

    bool isSecretRoom() const;

    bool playerHasKey() const;

protected:
    std::map<std::string, std::shared_ptr<Passage>> passageMap;
    std::vector<std::shared_ptr<Item>> items;
};


#endif //ZOORK_ROOM_H
