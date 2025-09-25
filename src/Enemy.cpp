#include "Enemy.hpp"

Enemy::Enemy(const Stats &stats, const std::string &name)
    : stats(stats), name(name) {}

// getters
const Stats &Enemy::get_stats() const { return stats; }
const std::string &Enemy::get_name() const { return name; }
