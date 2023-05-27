#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"

#include "Key.h"
#include "FriendlyNPCInteractCommand.h"
#include "HostileNPCInteractCommand.h"

int main() {
    std::shared_ptr<Room> start = std::make_shared<Room>("start-room",
                                                         "You are standing in an open field west of a white house, with a boarded front door.\n");

    std::shared_ptr<Room> south_of_house = std::make_shared<Room>("south-of-house",
                                                                  "You are facing the south side of a white house.  There is no door here, and all the windows are barred.\n");

    std::shared_ptr<Room> behind_house = std::make_shared<Room>("behind-house",
                                                                "You are behind the white house. A path leads into the forest to the east. In one corner of the house there is a small window which is slightly ajar.\n");

    std::shared_ptr<Room> forest = std::make_shared<Room>("forest",
                                                          "You are in a dense forest. The trees are tall and their branches create a canopy over your head, blocking out most of the sunlight. The forest seems to go on forever in all directions.\n");

    std::shared_ptr<Room> cave_entrance = std::make_shared<Room>("cave-entrance",
                                                                 "You are standing at the entrance of a dark cave. The air is damp and there is a musty smell. You can hear the sound of water dripping from somewhere inside the cave.\n");

    std::shared_ptr<Room> cave = std::make_shared<Room>("cave",
                                                        "You are inside the cave. It is pitch black and you can't see anything. You can hear the sound of water dripping and the echo of your footsteps.\n");

    std::shared_ptr<Room> underground_river = std::make_shared<Room>("underground-river",
                                                                     "You are standing on the bank of an underground river. The water is crystal clear and you can see small fish swimming in it. The sound of the water is soothing and relaxing.\n");

    std::shared_ptr<Room> treasure_room = std::make_shared<Room>("treasure-room",
                                                                 "You are in a room filled with treasure. There are piles of gold coins, silver bars, and precious gems all around you. You can't believe your luck!\n");

    std::shared_ptr<Room> secret_room = std::make_shared<Room>("secret-room",
                                                               "This is the secret room. It's hidden from plain sight.");

    std::shared_ptr<Room> cliff = std::make_shared<Room>("cliff",
                                                         "You are standing at the edge of a cliff. The view is breathtaking, with the vast expanse of the ocean stretching out before you. The sound of crashing waves fills the air.\n");

    std::shared_ptr<Room> beach = std::make_shared<Room>("beach",
                                                         "You are on a sandy beach. The sun is shining brightly, and the gentle breeze carries the salty smell of the ocean. Seagulls are soaring overhead.\n");

    std::shared_ptr<Room> underwater_cave = std::make_shared<Room>("underwater-cave",
                                                                   "You have discovered an underwater cave. Sunlight filters through the clear water, revealing a colorful array of coral and fish swimming around.\n");

//    std::shared_ptr<Item> key = std::make_shared<Item>("key", "A shiny golden key.");

    std::shared_ptr<Item> key = std::make_shared<Key>("key", "A small key that can unlock secrets.");
    start->addItem(key);

    std::shared_ptr<Item> sword = std::make_shared<Item>("sword", "A sharp and sturdy sword.");
    std::shared_ptr<Item> treasure = std::make_shared<Item>("treasure", "A chest filled with valuable treasures.");

//    start->addItem(key); // Add the key to the starting room.
    cave->addItem(sword); // Add the sword to the cave.
    secret_room->addItem(treasure); // Add the treasure chest to the secret room.

    Passage::createBasicPassage(start.get(), south_of_house.get(), "south", true);
    Passage::createBasicPassage(south_of_house.get(), behind_house.get(), "east", true);
    Passage::createBasicPassage(behind_house.get(), forest.get(), "east", true);
    Passage::createBasicPassage(forest.get(), cave_entrance.get(), "north", true);
    Passage::createBasicPassage(cave_entrance.get(), cave.get(), "enter", true);
    Passage::createBasicPassage(cave.get(), underground_river.get(), "down", true);
    Passage::createBasicPassage(underground_river.get(), treasure_room.get(), "west", true);
    Passage::createBasicPassage(treasure_room.get(), secret_room.get(), "unlock", true);
    Passage::createBasicPassage(secret_room.get(), start.get(), "south", true);
    Passage::createBasicPassage(start.get(), cliff.get(), "west", true);
    Passage::createBasicPassage(cliff.get(), beach.get(), "down", true);

    ZOOrkEngine zoork(start);

    zoork.run();

    return 0;
}