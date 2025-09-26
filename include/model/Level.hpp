#pragma once
#include "Room.hpp"
#include "model/character/Player.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  void run(Player &player);

private:
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
  void go(Player &player);
};
