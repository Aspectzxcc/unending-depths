#include "LevelView.hpp"
#include "Console.hpp"
#include "RoomView.hpp"
#include <iostream>

LevelView::LevelView(Level &level) : level(level) {
  commands["go north"] = [this]() { go("north"); };
  commands["go south"] = [this]() { go("south"); };
  commands["go east"] = [this]() { go("east"); };
  commands["go west"] = [this]() { go("west"); };
  commands["exit"] = [this]() { exit(); };
}

void LevelView::display() {
  std::string commandl;
  bool in_level = true;

  while (in_level) {
    Console::clear_screen();
    if (level.get_current_room_index() == 0) {
      std::cout << "You are in the starting room." << std::endl;
    } else {
      std::cout << "You are in room " << level.get_current_room_index()
                << std::endl;
    }
    std::cout << "Enter command (go <direction>/exit): ";
    std::getline(std::cin, commandl);

    handle_command(commandl);
  }
}

void LevelView::handle_command(const std::string &command) {
  auto it = commands.find(command);
  if (it != commands.end()) {
    it->second();
  } else {
    std::cout << "Invalid command." << std::endl;
  }
}

void LevelView::go(const std::string &direction) {
  if (level.get_current_room_index() >= level.get_rooms().size()) {
    std::cout << "You have reached the end of the level!" << std::endl;
    return;
  }

  level.add_room(std::make_unique<Room>());

  std::cout << "You are moving " << direction << " to room "
            << level.get_current_room_index() + 1 << std::endl;

  RoomView room_view(*level.get_rooms()[level.get_current_room_index()]);
  room_view.display();

  level.increment_current_room_index();
}

void LevelView::exit() {
  std::cout << "Exiting level." << std::endl;
  // break loop by exception to signal exit
  throw std::runtime_error("Exit Level");
}
