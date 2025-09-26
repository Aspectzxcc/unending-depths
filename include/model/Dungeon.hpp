#pragma once
#include "Level.hpp"
#include "model/character/Player.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Dungeon {
public:
  void run(Player &player);

private:
  std::vector<std::unique_ptr<Level>> levels;
  std::size_t current_level_index = 0;
  void enter(Player &player);
};
