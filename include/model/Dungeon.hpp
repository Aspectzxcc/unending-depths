#pragma once
#include "Level.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class Dungeon {
public:
  Dungeon();
  const std::size_t &get_current_level_index() const;
  const std::vector<std::unique_ptr<Level>> &get_levels() const;
  void add_level(std::unique_ptr<Level> level);
  void increment_current_level_index();

private:
  static constexpr std::size_t DEFAULT_NUM_LEVELS = 1;
  std::vector<std::unique_ptr<Level>> levels;
  std::size_t current_level_index = 0;
};
