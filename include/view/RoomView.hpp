#pragma once
#include "model/Room.hpp"
#include <functional>
#include <string>
#include <unordered_map>

class RoomView {
public:
  RoomView(Room &room);
  void display();
  void handle_command(const std::string &command);

private:
  Room &room;
  std::unordered_map<std::string, std::function<void()>> commands;
  void look();
  void exit();
};
