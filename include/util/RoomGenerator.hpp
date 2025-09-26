#pragma once
#include "model/Room.hpp"
#include <memory>

class RoomGenerator {
public:
  static std::unique_ptr<Room> generate_room(int dungeon_level);
};
