#pragma once
#include "Room.hpp"
#include "model/character/Player.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  Room &get_current_room();
  void add_room(std::unique_ptr<Room> room);

private:
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
  void go(Player &player);
};
