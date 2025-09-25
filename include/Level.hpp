#pragma once
#include "Room.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  Level();
  void display();

private:
  static constexpr std::size_t DEFAULT_NUM_ROOMS = 1;
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
};
