#include "model/character/Enemy.hpp"

Enemy::Enemy(const std::unordered_map<StatType, int> &stats,
             const std::string &name)
    : Character(stats, name) {}

void Enemy::attack(Character &target) {
  int enemy_strength = this->get_stats().at(StatType::STR);
  int target_health = target.get_stats().at(StatType::HP);
  target_health = std::max(0, target_health - enemy_strength);
  target.modify_stat(StatType::HP, target_health);
}
