#include "Game.hpp"
#include "util/Console.hpp"
#include <iostream>
#include <string>

void Game::run() {
  std::string command;
  bool is_running = true;

  while (is_running) {
    Console::clear_screen();
    std::cout << "Enter command (start/exit): ";
    std::getline(std::cin, command);

    if (command == "start") {
      break;
    } else if (command == "exit") {
      std::cout << "Exiting game." << std::endl;
      is_running = false;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
