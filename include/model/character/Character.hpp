#pragma once
#include "model/character/StatType.hpp"
#include <string>
#include <unordered_map>

class Character {
public:
  Character(const std::unordered_map<StatType, int> &stats,
            const std::string &name);
  virtual void attack(Character &target) = 0;
  const std::unordered_map<StatType, int> &get_stats() const;
  const std::string &get_name() const;
  void modify_stat(StatType type, int value);

private:
  std::unordered_map<StatType, int> stats;
  std::string name;
};
