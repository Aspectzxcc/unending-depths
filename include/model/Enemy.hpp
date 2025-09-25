#pragma once
#include "Stats.hpp"
#include <string>

class Enemy {
public:
  Enemy(const Stats &stats, const std::string &name);
  const Stats &get_stats() const;
  const std::string &get_name() const;

private:
  Stats stats;
  std::string name;
};
