#pragma once
#include "model/Room.hpp"

class RoomView {
public:
  void display(Room &room);

private:
  void display_enemies(Room &room);
  void display_loot(Room &room);
  bool looked = false;
};
