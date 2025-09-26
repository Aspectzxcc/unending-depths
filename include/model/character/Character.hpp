#pragma once
#include "model/character/StatType.hpp"
#include <string>
#include <unordered_map>

class Character {
public:
  Character(const std::unordered_map<StatType, int> &stats,
            const std::string &name);
  void attack(Character &target);
  const std::unordered_map<StatType, int> &get_stats() const;
  const std::string &get_name() const;

private:
  std::unordered_map<StatType, int> stats;
  std::string name;
};
