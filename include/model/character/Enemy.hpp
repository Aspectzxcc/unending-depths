#pragma once
#include "Character.hpp"

class Enemy : public Character {
public:
  Enemy(const std::unordered_map<StatType, int> &stats,
        const std::string &name);
  void attack(Character &target) override;
};
