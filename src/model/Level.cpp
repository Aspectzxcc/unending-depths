#include "model/Level.hpp"

Room &Level::get_current_room() { return *current_room; }

void Level::enter_new_room() {
  current_room = std::make_unique<Room>();
  current_room->generate();
  room_number++;
}
