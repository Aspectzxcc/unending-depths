#include "model/item/Weapon.hpp"

Weapon::Weapon(const std::string &name,
               const std::vector<StatModifier> &modifiers, int damage)
    : Item(name, modifiers), damage(damage) {}

int Weapon::get_damage() const { return damage; }
