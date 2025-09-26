#pragma once
#include "model/Stats.hpp"
#include <string>

class Character {
public:
  Character(const Stats &stats, const std::string &name);
  void attack(Character &target);
  const Stats &get_stats() const;
  const std::string &get_name() const;

private:
  Stats stats;
  std::string name;
};
