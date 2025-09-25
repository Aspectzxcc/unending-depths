#include "model/Dungeon.hpp"

Dungeon::Dungeon() {
  std::size_t MIN_NUM_LEVELS = 1;

  for (std::size_t i = 0; i < MIN_NUM_LEVELS; ++i) {
    levels.push_back(std::make_unique<Level>());
  }
}

bool Dungeon::descend() {
  if (current_level_index >= levels.size()) {
    return false;
  }
  ++current_level_index;
  return true;
}

// getters
const std::size_t &Dungeon::get_current_level_index() const {
  return current_level_index;
}
const std::vector<std::unique_ptr<Level>> &Dungeon::get_levels() const {
  return levels;
}

Level &Dungeon::get_current_level() {
  return *(levels[current_level_index - 1]);
}
