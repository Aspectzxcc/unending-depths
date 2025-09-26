#include "model/Level.hpp"

Room &Level::get_current_room() { return *rooms[rooms.size() - 1]; }

void Level::add_room(std::unique_ptr<Room> room) {
  rooms.push_back(std::move(room));
}
