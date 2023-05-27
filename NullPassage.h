//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_NULLPASSAGE_H
#define ZOORK_NULLPASSAGE_H

#include "Passage.h"
#include "Room.h"

class Room; // Forward declaration of Room class

class NullPassage : public Passage {
public:
//    explicit NullPassage(Room*);
    explicit NullPassage(Room* room);
};


#endif //ZOORK_NULLPASSAGE_H
