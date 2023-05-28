////
//// Created by Tommy Bui on 27/5/2023.
////
//
//#ifndef ZOORK_DOOR_H
//#define ZOORK_DOOR_H
//
//#include "Passage.h"
//#include "Item.h"
//
//class Door : public Passage {
//public:
//    Door(const std::string& n, const std::string& d, Room* from, Room* to, std::shared_ptr<Item> item);
//
//    bool isLocked() const;
//    void unlock(const std::shared_ptr<Item>& item);
//
//protected:
//    std::shared_ptr<Item> requiredItem;
//};
//
//#endif //ZOORK_DOOR_H

#ifndef DOOR_H
#define DOOR_H

#include "Passage.h"

class Door : public Passage {
private:
    bool locked;

public:
    Door(const std::string& name, const std::string& description, Room* from, Room* to, std::shared_ptr<Item> requiredItem);

    bool isLocked() const;
    void unlock();
};

#endif // DOOR_H
