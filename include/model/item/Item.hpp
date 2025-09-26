#pragma once
#include "modifier/StatModifier.hpp"
#include <string>
#include <vector>

class Item {
public:
  Item(const std::string &name,
       const std::vector<StatModifier> &stat_modifiers = {});
  const std::string &get_name() const;
  const std::vector<StatModifier> &get_stat_modifiers() const;

private:
  std::string name;
  std::vector<StatModifier> stat_modifiers;
};
