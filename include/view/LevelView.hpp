#pragma once
#include "model/Level.hpp"
#include <functional>
#include <string>
#include <unordered_map>

class LevelView {
public:
  LevelView(Level &level);
  void display();
  void handle_command(const std::string &command);

private:
  Level &level;
  std::unordered_map<std::string, std::function<void()>> commands;
  void go(const std::string &direction);
  void exit();
};
