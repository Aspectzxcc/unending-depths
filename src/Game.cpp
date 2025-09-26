#include "Game.hpp"
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
      Dungeon dungeon;
      Player player({100, 10, 5, 5}, "Hero");
      dungeon.run(player);
    } else if (command == "exit") {
      std::cout << "Exiting game." << std::endl;
      return;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
