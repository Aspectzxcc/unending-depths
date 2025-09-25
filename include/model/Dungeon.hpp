#pragma once
#include "Level.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Dungeon {
public:
  Dungeon();
  bool descend();
  const std::size_t &get_current_level_index() const;
  const std::vector<std::unique_ptr<Level>> &get_levels() const;
  Level &get_current_level();

private:
  std::vector<std::unique_ptr<Level>> levels;
  std::size_t current_level_index = 0;
};
