#include "model/Level.hpp"
#include "controller/RoomController.hpp"

Room &Level::get_current_room() { return *rooms[current_room_index - 1]; }

void Level::add_room(std::unique_ptr<Room> room) {
  rooms.push_back(std::move(room));
}

void Level::go(Player &player) {
  std::unique_ptr<Room> new_room = std::make_unique<Room>();
  rooms.push_back(std::move(new_room));
  current_room_index++;
  RoomController controller;
  RoomView view;
  controller.run(*rooms[current_room_index - 1], view, player);
}
