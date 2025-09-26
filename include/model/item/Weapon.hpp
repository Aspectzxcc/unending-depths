#pragma once
#include "Item.hpp"
#include <string>

class Weapon : public Item {
public:
  Weapon(const std::string &name, int damage);
  const std::string &get_name() const;
  int get_damage() const;

private:
  int damage;
  std::string name;
};
