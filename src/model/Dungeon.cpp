#include "model/Dungeon.hpp"
#include "util/Console.hpp"
#include <iostream>
#include <string>

void Dungeon::run() {
  std::string command;

  while (true) {
    Console::clear_screen();
    std::cout << "You are at dungeon level " << current_level_index + 1
              << std::endl;
    std::cout << "Enter Comand (enter/exit): ";
    std::getline(std::cin, command);

    if (command == "enter") {
      enter();
    } else if (command == "exit") {
      std::cout << "Exiting the dungeon." << std::endl;
      return;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}

void Dungeon::enter() {
  std::unique_ptr<Level> new_level = std::make_unique<Level>();
  levels.push_back(std::move(new_level));
  current_level_index++;
  levels[current_level_index - 1]->run();
}
