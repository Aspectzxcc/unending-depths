#include "model/item/Gear.hpp"

Gear::Gear(const std::string &name,
           const std::unordered_map<StatType, int> &stat_bonuses)
    : Item(name), stat_bonuses(stat_bonuses) {}
