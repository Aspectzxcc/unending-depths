#pragma once
#include "model/Dungeon.hpp"
#include "model/character/Player.hpp"
#include "view/DungeonView.hpp"

class DungeonController {
public:
  void run(Dungeon &dungeon, DungeonView &dungeonView, Player &player);
};
