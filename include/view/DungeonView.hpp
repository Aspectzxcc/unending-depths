#pragma once
#include "model/Dungeon.hpp"
#include <functional>
#include <string>
#include <unordered_map>

class DungeonView {
public:
  DungeonView(Dungeon &dungeon);
  void display();
  void handle_command(const std::string &command);

private:
  Dungeon &dungeon;
  std::unordered_map<std::string, std::function<void()>> commands;
  void descend();
  void exit();
};
