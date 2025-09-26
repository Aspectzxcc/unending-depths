#pragma once
#include "character/Enemy.hpp"
#include "item/Item.hpp"
#include "model/character/Player.hpp"
#include <vector>

class Room {
public:
  Room();
  void run(Player &player);

private:
  std::vector<Enemy> enemies;
  std::vector<Item> loot;
  bool looked = false;
  void look();
};
