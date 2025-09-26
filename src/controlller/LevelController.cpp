#include "controller/LevelController.hpp"
#include "controller/RoomController.hpp"
#include "view/RoomView.hpp"
#include <iostream>

void LevelController::run(Level &level, LevelView &levelView, Player &player) {
  std::string command;

  while (true) {
    levelView.display();
    std::getline(std::cin, command);

    if (command == "go") {
      level.add_room(std::make_unique<Room>());
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
