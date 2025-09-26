#include "view/RoomView.hpp"
#include "util/Console.hpp"
#include <iostream>

void RoomView::display(Room &room) {
  Console::clear_screen();
  std::cout << "You are in a room." << std::endl;

  if (looked) {
    display_enemies(room);
    display_loot(room);
  }
}
