#pragma once
#include "character/Enemy.hpp"
#include "item/Item.hpp"
#include <memory>
#include <vector>

class Room {
public:
  Room(std::vector<std::unique_ptr<Enemy>> enemies = {},
       std::vector<std::unique_ptr<Item>> loot = {});
  const std::vector<std::unique_ptr<Enemy>> &get_enemies() const;
  const std::vector<std::unique_ptr<Item>> &get_loot() const;
  std::unique_ptr<Item> take_loot(int index);
  Enemy &get_enemy(int index);
  void remove_enemy(int index);

private:
  std::vector<std::unique_ptr<Enemy>> enemies;
  std::vector<std::unique_ptr<Item>> loot;
};
