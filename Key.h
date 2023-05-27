#ifndef ZOORK_KEY_H
#define ZOORK_KEY_H

#include "Item.h"
#include "Room.h"
#include "Passage.h"

class Key : public Item {
public:
    Key(const std::string& n, const std::string& d);

    void use(Room* room);

private:
    // Add any additional member variables or methods as needed
};

#endif //ZOORK_KEY_H
