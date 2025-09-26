#include "view/DungeonView.hpp"
#include "util/Console.hpp"
#include <iostream>

void DungeonView::display() {
  Console::clear_screen();
  std::cout << "You are in the dungeon." << std::endl;
  std::cout << "Available commands: enter, exit" << std::endl;
}

void DungeonView::display_message(const std::string &message) {
  std::cout << message << std::endl;
}
