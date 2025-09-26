#include "model/Dungeon.hpp"

Level &Dungeon::get_current_level() { return *levels[levels.size() - 1]; }

void Dungeon::add_level(std::unique_ptr<Level> level) {
  levels.push_back(std::move(level));
}
