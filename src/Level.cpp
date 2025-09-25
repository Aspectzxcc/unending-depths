#include "Level.hpp"
#include "Console.hpp"
#include <iostream>

Level::Level() {
  for (std::size_t i = 0; i < DEFAULT_NUM_ROOMS; ++i) {
    rooms.push_back(std::make_unique<Room>());
  }
}

void Level::display() {
  std::string commandl;
  bool in_level = true;

  while (in_level) {
    Console::clear_screen();
    if (current_room_index == 0) {
      std::cout << "You are in the starting room." << std::endl;
    } else {
      std::cout << "You are in room " << current_room_index << std::endl;
    }
    std::cout << "Enter command (go <direction>/exit): ";
    std::getline(std::cin, commandl);

    if (commandl.rfind("go ", 0) == 0) {
      if (current_room_index >= rooms.size()) {
        std::cout << "You have reached the end of the level!" << std::endl;
        in_level = false;
        return;
      }

      rooms.emplace_back(std::make_unique<Room>());

      std::string direction = commandl.substr(3);
      std::cout << "You are moving " << direction << " to room "
                << current_room_index + 1 << std::endl;
      rooms[current_room_index]->display();

      ++current_room_index;
    } else if (commandl == "exit") {
      std::cout << "Exiting level." << std::endl;
      in_level = false;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
