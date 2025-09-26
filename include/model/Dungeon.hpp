#pragma once
#include "Level.hpp"
#include <cstddef>
#include <memory>

class Dungeon {
public:
  Level &get_current_level();
  void enter_new_level();

private:
  std::unique_ptr<Level> current_level;
  std::size_t level_number{0};
};
