#pragma once
#include "Room.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  Level();
  bool spawn_room();
  const std::size_t &get_current_room_index() const;
  const std::vector<std::unique_ptr<Room>> &get_rooms() const;
  const Room &get_current_room() const;
  void add_room(std::unique_ptr<Room> room);

private:
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
};
