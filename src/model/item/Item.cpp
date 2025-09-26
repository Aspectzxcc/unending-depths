#include "model/item/Item.hpp"
#include "model/item/modifier/StatModifier.hpp"

Item::Item(const std::string &name, const std::vector<StatModifier> &modifiers)
    : name(name), stat_modifiers(modifiers) {}

// getters
const std::string &Item::get_name() const { return name; }
const std::vector<StatModifier> &Item::get_stat_modifiers() const {
  return stat_modifiers;
}
