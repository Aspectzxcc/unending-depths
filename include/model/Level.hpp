#pragma once
#include "Room.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  void run();

private:
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
  void go();
};
