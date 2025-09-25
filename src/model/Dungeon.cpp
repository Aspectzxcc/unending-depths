#include "Dungeon.hpp"

Dungeon::Dungeon() {
  for (std::size_t i = 0; i < DEFAULT_NUM_LEVELS; ++i) {
    levels.push_back(std::make_unique<Level>());
  }
}

// getters
const std::size_t &Dungeon::get_current_level_index() const {
  return current_level_index;
}
const std::vector<std::unique_ptr<Level>> &Dungeon::get_levels() const {
  return levels;
}

// setters
void Dungeon::add_level(std::unique_ptr<Level> level) {
  levels.push_back(std::move(level));
}

void Dungeon::increment_current_level_index() { ++current_level_index; }
