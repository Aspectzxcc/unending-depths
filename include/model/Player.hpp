#pragma once
#include "model/Stats.hpp"
#include "model/item/Item.hpp"
#include <memory>
#include <string>
#include <vector>

class Player {
public:
  Player(int health, const Stats &stats);

private:
  int health;
  std::string name;
  Stats stats;
  std::vector<std::unique_ptr<Item>> inventory;
};
