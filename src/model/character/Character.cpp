#include "model/character/Character.hpp"

Character::Character(const std::unordered_map<StatType, int> &stats,
                     const std::string &name)
    : stats(stats), name(name) {}

const std::unordered_map<StatType, int> &Character::get_stats() const {
  return stats;
}
const std::string &Character::get_name() const { return name; }
void Character::modify_stat(StatType type, int value) { stats[type] = value; }
