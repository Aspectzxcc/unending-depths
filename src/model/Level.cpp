#include "model/Level.hpp"
#include "util/RoomGenerator.hpp"

Level::Level(std::size_t dungeon_level) : dungeon_level(dungeon_level) {}

Room &Level::get_current_room() { return *current_room; }

void Level::enter_new_room() {
  current_room = RoomGenerator::generate_room(dungeon_level);
  room_number++;
}
