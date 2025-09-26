#include "controller/LevelController.hpp"
#include "controller/RoomController.hpp"
#include <iostream>

void LevelController::run(Level &level, LevelView &levelView, Player &player) {
  std::string command;

  while (true) {
    levelView.display();
    std::getline(std::cin, command);

    if (command == "go") {
      level.enter_new_room();
      RoomController controller;
      RoomView view;
      controller.run(level.get_current_room(), view, player);
    } else if (command == "exit") {
      return;
    } else {
      levelView.display_message("Invalid command.");
    }
  }
}
