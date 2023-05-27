//
// Created by Richard Skarbez on 5/7/23.
//

#include "RoomDefaultEnterCommand.h"
#include <iostream>
using namespace std;

void RoomDefaultEnterCommand::execute() {
    std::cout << gameObject->getDescription() << "\n";
}