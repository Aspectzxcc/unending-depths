#include "model/Level.hpp"
#include "util/RNG.hpp"

Level::Level() {
  std::size_t MIN_NUM_ROOMS = 1;
  std::size_t MAX_NUM_ROOMS = 10;
  std::size_t generated_rooms_count = RNG::range(MIN_NUM_ROOMS, MAX_NUM_ROOMS);

  for (std::size_t i = 1; i <= generated_rooms_count; ++i) {
    rooms.push_back(std::make_unique<Room>());
  }
}

bool Level::spawn_room() {
  if (current_room_index >= rooms.size()) {
    return false;
  }
  rooms.push_back(std::make_unique<Room>());
  ++current_room_index;
  return true;
}

// getters
const std::size_t &Level::get_current_room_index() const {
  return current_room_index;
}

const std::vector<std::unique_ptr<Room>> &Level::get_rooms() const {
  return rooms;
}

const Room &Level::get_current_room() const {
  return *(rooms[current_room_index]);
}

// setters
void Level::add_room(std::unique_ptr<Room> room) {
  rooms.push_back(std::move(room));
}
