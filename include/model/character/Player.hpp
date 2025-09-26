#pragma once
#include "Character.hpp"
#include "model/item/Item.hpp"
#include "model/item/Weapon.hpp"
#include <memory>
#include <vector>

class Player : public Character {
public:
  Player(const std::unordered_map<StatType, int> &stats,
         const std::string &name);
  const std::vector<std::unique_ptr<Item>> &get_inventory() const;
  void add_item(std::unique_ptr<Item> item);
  void remove_item(size_t index);

private:
  std::unique_ptr<Weapon> equipped_weapon;
  std::vector<std::unique_ptr<Item>> inventory;
};
