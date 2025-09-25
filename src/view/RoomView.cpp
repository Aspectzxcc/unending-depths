#include "view/RoomView.hpp"
#include "utils/Console.hpp"
#include <iostream>

RoomView::RoomView(Room &room, Level &level)
    : BaseView<Room>(room), level(level) {
  commands["go north"] = [this]() { go("north"); };
  commands["go south"] = [this]() { go("south"); };
  commands["go east"] = [this]() { go("east"); };
  commands["go west"] = [this]() { go("west"); };
  commands["go northeast"] = [this]() { go("northeast"); };
  commands["go northwest"] = [this]() { go("northwest"); };
  commands["go southeast"] = [this]() { go("southeast"); };
  commands["go southwest"] = [this]() { go("southwest"); };
  commands["look"] = [this]() { look(); };
  commands["exit"] = [this]() { exit(); };
}

void RoomView::render() {
  std::cout << "You are in room " << level.get_current_room_index() + 1
            << std::endl;
  if (looked) {
    for (const auto &enemy : model.get_enemies()) {
      std::cout << "Enemy: " << enemy.get_name() << std::endl;
    }
    for (const auto &item : model.get_loot()) {
      std::cout << "Loot: " << item.get_name() << std::endl;
    }
  }
  std::cout << "Enter command (go <direction>/look/exit): ";
}

void RoomView::go(const std::string &_) {
  if (!level.spawn_room()) {
    std::cout << "No more rooms to explore in this level." << std::endl;
    Console::wait_for_keypress();
    return;
  }
}

void RoomView::look() {
  looked = true;
  std::cout << "You look around the room." << std::endl;

  if (model.get_enemies().empty() && model.get_loot().empty()) {
    std::cout << "The room is empty." << std::endl;
  }

  for (const auto &enemy : model.get_enemies()) {
    std::cout << "You see an enemy: " << enemy.get_name() << std::endl;
  }

  for (const auto &item : model.get_loot()) {
    std::cout << "You see a loot item: " << item.get_name() << std::endl;
  }
  Console::wait_for_keypress();
}

void RoomView::exit() {
  std::cout << "Exiting room." << std::endl;
  running = false;
}
