//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"

#include "Key.h"

#include <utility>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start) {
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go") {
            handleGoCommand(arguments);
        } else if ((command == "look") || (command == "inspect")) {
            handleLookCommand(arguments);
        } else if ((command == "take") || (command == "get")) {
            handleTakeCommand(arguments);
        } else if (command == "drop") {
            handleDropCommand(arguments);
        } else if (command == "use") {
            handleUseCommand(arguments);
        } else if (command == "inventory") {
            handleInventoryCommand();
        } else if (command == "quit") {
            handleQuitCommand(arguments);
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north") {
        direction = "north";
    } else if (arguments[0] == "s" || arguments[0] == "south") {
        direction = "south";
    } else if (arguments[0] == "e" || arguments[0] == "east") {
        direction = "east";
    } else if (arguments[0] == "w" || arguments[0] == "west") {
        direction = "west";
    } else if (arguments[0] == "u" || arguments[0] == "up") {
        direction = "up";
    } else if (arguments[0] == "d" || arguments[0] == "down") {
        direction = "down";
    } else {
        direction = arguments[0];
    }

    Room* currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
//    player->setCurrentRoom(passage->getTo());
//    passage->enter();

    if (passage != nullptr && passage->getTo() != nullptr) {
        player->setCurrentRoom(passage->getTo());
        passage->enter();
    } else {
        std::cout << "You can't go that way.\n";
    }
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    Room* currentRoom = player->getCurrentRoom();

    if (arguments.empty()) {
        // No specific target, print the description of the current room
        currentRoom->enter();
    } else {
        std::string target = makeLowercase(arguments[0]);

        // Check if the target is an item in the room
        std::shared_ptr<Item> item = currentRoom->getItem(target);
        if (item) {
            std::cout << item->getDescription() << std::endl;
        } else {
            // Check if the target is an item in the player's inventory
            item = player->getItem(target);
            if (item) {
                std::cout << item->getDescription() << std:: endl;
            } else {
                std::cout << "There is no " << target << " here." << std::endl;
            }
        }
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Take what?\n";
    }

    std::string itemName = makeLowercase(arguments[0]);
    Room* currentRoom = player->getCurrentRoom();
    std::shared_ptr<Item> item = currentRoom->getItem(itemName);

    if (item) {
        player ->addItem(item);
        currentRoom->removeItem(itemName);
        std::cout << "You take the " << item->getName() << "." << std::endl;
    } else {
        std::cout << "There is no " << itemName << " here." << std::endl;
    }
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Drop what?\n";
        return;
    }

    std::string itemName = makeLowercase(arguments[0]);
    std::shared_ptr<Item> item = player->getItem(itemName);

    if (item) {
        Room* currentRoom = player->getCurrentRoom();
        currentRoom->addItem(item);
        player->removeItem(itemName);
        std::cout << "You drop the " << item->getName() << "." << std::endl;
    } else {
        std::cout << "You don't have a " << itemName << "." << std::endl;
    }
}

void ZOOrkEngine::handleInventoryCommand() {
    std::vector<std::shared_ptr<Item>> inventory = player->getInventory();
    if (inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    } else {
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item->getName() << std::endl;
        }
    }
}

void ZOOrkEngine::handleUseCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Please specify the item you want to use." << std::endl;
        return;
    }

    std::string itemName = makeLowercase(arguments[0]);

    // Check if the player has the key in their inventory
    std::shared_ptr<Item> item = player->getItem(itemName);
    if (item && dynamic_cast<Key*>(item.get())) {
        Key* key = dynamic_cast<Key*>(item.get());

        // Determine the current room the player is in
        Room* currentRoom = player->getCurrentRoom();

        // Use the key on the current room
        key->use(currentRoom);
    } else {
        std::cout << "You don't have a key." << std::endl;
    }
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        gameOver = true;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
