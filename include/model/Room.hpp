#pragma once
#include "character/Enemy.hpp"
#include "item/Item.hpp"
#include <vector>

class Room {
public:
  Room();
  const std::vector<Enemy> &get_enemies() const;
  const std::vector<Item> &get_loot() const;
  Enemy &get_enemy(int index);
  void remove_enemy(int index);

private:
  std::vector<Enemy> enemies;
  std::vector<Item> loot;
  bool looked = false;
};
