#include "model/Dungeon.hpp"

Level &Dungeon::get_current_level() { return *current_level; }

void Dungeon::enter_new_level() {
  current_level = std::make_unique<Level>();
  level_number++;
}
