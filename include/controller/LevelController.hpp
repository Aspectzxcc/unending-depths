#pragma once
#include "model/Level.hpp"
#include "model/character/Player.hpp"
#include "view/LevelView.hpp"

class LevelController {
public:
  void run(Level &level, LevelView &levelView, Player &player);
};
