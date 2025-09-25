#pragma once
#include "Room.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Level {
public:
  Level();
  const std::size_t &get_current_room_index() const;
  const std::vector<std::unique_ptr<Room>> &get_rooms() const;
  void add_room(std::unique_ptr<Room> room);
  void increment_current_room_index();

private:
  static constexpr std::size_t DEFAULT_NUM_ROOMS = 1;
  std::vector<std::unique_ptr<Room>> rooms;
  std::size_t current_room_index = 0;
};
