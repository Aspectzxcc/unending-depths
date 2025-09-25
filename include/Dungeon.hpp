#pragma once
#include "Level.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Dungeon {
public:
  Dungeon();
  void display();

private:
  static constexpr std::size_t DEFAULT_NUM_LEVELS = 1;
  std::vector<std::unique_ptr<Level>> levels;
  std::size_t current_level_index = 0;
};
