#pragma once
#include "model/item/Gear.hpp"
#include <string>

class Weapon : public Gear {
public:
  Weapon(const std::string &name,
         const std::unordered_map<StatType, int> &stat_bonuses, int damage);
  int get_damage() const;

private:
  int damage;
};
