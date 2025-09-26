#include "controller/DungeonController.hpp"
#include "controller/LevelController.hpp"
#include <iostream>

void DungeonController::run(Dungeon &dungeon, DungeonView &dungeonView,
                            Player &player) {
  std::string command;

  while (true) {
    dungeonView.display();
    std::getline(std::cin, command);

    if (command == "enter") {
      dungeon.enter_new_level();
      LevelController controller;
      LevelView view;
      controller.run(dungeon.get_current_level(), view, player);
      break;
    } else if (command == "exit") {
      return;
    } else {
      dungeonView.display_message("Invalid command.");
    }
  }
}
