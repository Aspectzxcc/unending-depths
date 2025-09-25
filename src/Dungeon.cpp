#include "Dungeon.hpp"
#include <iostream>

Dungeon::Dungeon() {
  for (std::size_t i = 0; i < DEFAULT_NUM_LEVELS; ++i) {
    levels.push_back(std::make_unique<Level>());
  }
}

void Dungeon::display() {
  std::string command;
  bool in_dungeon = true;

  while (in_dungeon) {
    if (current_level_index == 0) {
      std::cout << "You are at the entrance of the dungeon." << std::endl;
    } else {
      std::cout << "You are at level " << current_level_index << std::endl;
    }
    std::cout << "Enter command (descend/exit): " << std::endl;
    std::getline(std::cin, command);

    if (command == "descend") {
      if (current_level_index >= levels.size()) {
        std::cout << "You have reached the bottom of the dungeon!" << std::endl;
        in_dungeon = false;
        return;
      }

      std::cout << "You are descending to level " << current_level_index + 1
                << std::endl;
      levels[current_level_index]->display();

      ++current_level_index;
    } else if (command == "exit") {
      std::cout << "Exiting dungeon." << std::endl;
      in_dungeon = false;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
