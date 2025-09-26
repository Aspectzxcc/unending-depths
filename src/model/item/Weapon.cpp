#include "model/item/Weapon.hpp"

Weapon::Weapon(const std::string &name,
               const std::unordered_map<StatType, int> &stat_bonuses,
               int damage)
    : Gear(name, stat_bonuses), damage(damage) {}

int Weapon::get_damage() const { return damage; }
