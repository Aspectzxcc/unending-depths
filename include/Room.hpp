#pragma once
#include "Enemy.hpp"
#include "Item.hpp"
#include <vector>

class Room {
public:
  Room();
  void display();

private:
  std::vector<Enemy> enemies;
  std::vector<Item> loot;
};
