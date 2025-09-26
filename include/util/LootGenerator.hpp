#pragma once
#include "model/item/Item.hpp"
#include "model/item/Weapon.hpp"
#include <memory>

class LootGenerator {
public:
  static std::unique_ptr<Item> generate_item(int dungeon_level);

private:
  static std::unique_ptr<Weapon> generate_weapon(int dungeon_level);

  static std::string random_weapon_prefix();
  static std::string random_weapon_material();
  static std::string random_weapon_type();
  static std::string random_suffix();
};
