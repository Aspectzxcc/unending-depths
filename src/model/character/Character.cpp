#include "model/character/Character.hpp"
#include <algorithm>

Character::Character(const std::unordered_map<StatType, int> &stats,
                     const std::string &name)
    : stats(stats), name(name) {}

void Character::attack(Character &target) {
  int damage = std::max(0, stats.at(StatType::STR));
  target.stats.at(StatType::HP) =
      std::max(0, target.stats.at(StatType::HP) - damage);
}

const std::unordered_map<StatType, int> &Character::get_stats() const {
  return stats;
}
const std::string &Character::get_name() const { return name; }
