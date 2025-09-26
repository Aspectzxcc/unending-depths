#include "model/Level.hpp"
#include "util/Console.hpp"
#include <iostream>
#include <string>

void Level::run() {
  std::string command;

  while (true) {
    Console::clear_screen();
    std::cout << "Enter Command (go/exit): ";
    std::getline(std::cin, command);

    if (command == "go") {
      go();
    } else if (command == "exit") {
      std::cout << "Exiting the level." << std::endl;
      return;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}

void Level::go() {
  std::unique_ptr<Room> new_room = std::make_unique<Room>();
  rooms.push_back(std::move(new_room));
  current_room_index++;
  rooms[current_room_index - 1]->run();
}
