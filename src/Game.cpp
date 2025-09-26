#include "Game.hpp"
#include "controller/DungeonController.hpp"
#include "model/Dungeon.hpp"
#include "model/character/Player.hpp"
#include "util/Console.hpp"
#include <iostream>
#include <string>

void Game::run() {
  std::string command;

  while (true) {
    Console::clear_screen();
    std::cout << "Enter command (start/exit): ";
    std::getline(std::cin, command);

    if (command == "start") {
      DungeonController controller;
      DungeonView view;
      Dungeon dungeon;
      Player player(std::unordered_map<StatType, int>{{StatType::HP, 100},
                                                      {StatType::STR, 10},
                                                      {StatType::DEX, 10},
                                                      {StatType::CON, 10}},
                    "Hero");
      controller.run(dungeon, view, player);
    } else if (command == "exit") {
      std::cout << "Exiting game." << std::endl;
      return;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
