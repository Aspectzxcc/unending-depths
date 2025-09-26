#include "model/item/Weapon.hpp"

Weapon::Weapon(const std::string &name, int damage)
    : Item(name), damage(damage), name(name) {}

const std::string &Weapon::get_name() const { return name; }
int Weapon::get_damage() const { return damage; }
