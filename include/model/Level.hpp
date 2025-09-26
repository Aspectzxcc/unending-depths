#pragma once
#include "Room.hpp"
#include <cstddef>
#include <memory>

class Level {
public:
  Room &get_current_room();
  void enter_new_room();

private:
  std::unique_ptr<Room> current_room;
  std::size_t room_number = 0;
};
