#include "model/character/Character.hpp"
#include <algorithm>

Character::Character(const Stats &stats, const std::string &name)
    : stats(stats), name(name) {}

void Character::attack(Character &target) {
  int damage = std::max(0, stats.str);
  target.stats.hp = std::max(0, target.stats.hp - damage);
}
const Stats &Character::get_stats() const { return stats; }
const std::string &Character::get_name() const { return name; }
