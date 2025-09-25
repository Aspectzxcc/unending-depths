#include "RoomView.hpp"
#include "Console.hpp"
#include <iostream>

RoomView::RoomView(Room &room) : room(room) {
  commands["look"] = [this]() { look(); };
  commands["exit"] = [this]() { exit(); };
}

void RoomView::handle_command(const std::string &command) {
  auto it = commands.find(command);
  if (it != commands.end()) {
    it->second();
  } else {
    std::cout << "Invalid command." << std::endl;
    Console::wait_for_keypress();
  }
}

void RoomView::display() {
  std::string command;
  bool in_room = true;

  while (in_room) {
    Console::clear_screen();
    std::cout << "You have entered a room." << std::endl;

    std::cout << "Enemies in the room:" << std::endl;
    for (const auto &enemy : room.get_enemies()) {
      std::cout << "- " << enemy.get_name() << " (HP: " << enemy.get_stats().hp
                << ")" << std::endl;
    }

    std::cout << "Loot in the room:" << std::endl;
    for (const auto &item : room.get_loot()) {
      std::cout << "- " << item.get_name() << std::endl;
    }

    std::cout << "Enter command (look/exit): ";
    std::getline(std::cin, command);

    try {
      handle_command(command);
    } catch (const std::runtime_error &e) {
      if (std::string(e.what()) == "Exit room") {
        in_room = false;
      } else {
        throw;
      }
    }
  }
}

void RoomView::look() {
  std::cout << "You look around the room." << std::endl;
  if (room.get_enemies().empty() && room.get_loot().empty()) {
    std::cout << "The room is empty." << std::endl;
  }
  Console::wait_for_keypress();
}

void RoomView::exit() {
  std::cout << "Exiting room." << std::endl;
  // break loop by exception to signal exit
  throw std::runtime_error("Exit room");
}
