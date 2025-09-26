#include "model/Level.hpp"

Level::Level(int dungeon_level) : dungeon_level(dungeon_level) {}

Room &Level::get_current_room() { return *current_room; }

void Level::enter_new_room() {
  current_room = std::make_unique<Room>();
  current_room->generate(dungeon_level);
  room_number++;
}
