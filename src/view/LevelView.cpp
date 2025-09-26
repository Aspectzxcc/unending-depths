#include "view/LevelView.hpp"
#include "util/Console.hpp"
#include <iostream>

void LevelView::display() {
  Console::clear_screen();
  std::cout << "You are in a level." << std::endl;
  std::cout << "Available commands: go, exit" << std::endl;
}

void LevelView::display_message(const std::string &message) {
  std::cout << message << std::endl;
}
