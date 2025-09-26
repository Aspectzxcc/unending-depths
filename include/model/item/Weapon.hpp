#pragma once
#include "Item.hpp"

class Weapon : public Item {
public:
  Weapon(const std::string &name, int damage);
  int get_damage() const;

private:
  int damage;
};
