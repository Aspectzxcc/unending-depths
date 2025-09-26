#pragma once
#include "model/Room.hpp"

class RoomView {
public:
  void display(Room &room);
  void display_look(Room &room);
  void display_attack(bool enemy_present, int enemy_hp);
  void display_message(const std::string &message);

private:
  void display_enemies(Room &room);
  void display_loot(Room &room);
  bool looked = false;
};
