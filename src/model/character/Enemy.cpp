#include "model/character/Enemy.hpp"

Enemy::Enemy(const std::unordered_map<StatType, int> &stats,
             const std::string &name)
    : Character(stats, name) {}
