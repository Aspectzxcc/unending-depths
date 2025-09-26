#pragma once
#include "Level.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Dungeon {
public:
  Level &get_current_level();
  void add_level(std::unique_ptr<Level> level);

private:
  std::vector<std::unique_ptr<Level>> levels;
  std::size_t current_level_index = 0;
};
