#pragma once
#include "model/character/Player.hpp"
#include "view/RoomView.hpp"

class RoomController {
public:
  void run(Room &room, RoomView &roomView, Player &player);
};
