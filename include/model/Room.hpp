#pragma once
#include "Enemy.hpp"
#include "Item.hpp"
#include <vector>

class Room {
public:
  Room();
  const std::vector<Enemy> &get_enemies() const;
  const std::vector<Item> &get_loot() const;

private:
  std::vector<Enemy> enemies;
  std::vector<Item> loot;
};
