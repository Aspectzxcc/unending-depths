#pragma once
#include "Character.hpp"

class Enemy : public Character {
public:
  Enemy(const Stats &stats, const std::string &name);
};
