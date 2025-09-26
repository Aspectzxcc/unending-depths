#pragma once
#include "Item.hpp"
#include <string>

class Weapon : public Item {
public:
  Weapon(const std::string &name, const std::vector<StatModifier> &modifiers,
         int damage);
  int get_damage() const;

private:
  int damage;
};
