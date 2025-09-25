#include "Level.hpp"

Level::Level() {
  for (std::size_t i = 0; i < DEFAULT_NUM_ROOMS; ++i) {
    rooms.push_back(std::make_unique<Room>());
  }
}

// getters
const std::size_t &Level::get_current_room_index() const {
  return current_room_index;
}

const std::vector<std::unique_ptr<Room>> &Level::get_rooms() const {
  return rooms;
}

// setters
void Level::add_room(std::unique_ptr<Room> room) {
  rooms.push_back(std::move(room));
}

void Level::increment_current_room_index() { ++current_room_index; }
