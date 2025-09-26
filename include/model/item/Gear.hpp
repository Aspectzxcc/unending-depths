#pragma once
#include "model/character/StatType.hpp"
#include "model/item/Item.hpp"
#include <string>
#include <unordered_map>

class Gear : public Item {
public:
  Gear(const std::string &name,
       const std::unordered_map<StatType, int> &stat_bonuses);
  const std::unordered_map<StatType, int> &get_stat_bonuses() const;

private:
  std::unordered_map<StatType, int> stat_bonuses;
};
