#include "util/Console.hpp"
#include <iostream>
#include <limits>

void Console::print_dashes(int count) {
  for (int i = 0; i < count; ++i) {
    std::cout << "-";
  }
  std::cout << std::endl;
}

void Console::clear_screen() {
  std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear screen
}

void Console::wait_for_keypress() {
  std::cout << "Press Enter to continue...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
