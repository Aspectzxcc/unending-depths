#include "util/LootGenerator.hpp"
#include "model/character/StatType.hpp"
#include "util/RNG.hpp"
#include <vector>

const std::unordered_map<std::string, int> weapon_prefix_bonus = {
    {"Sharp", 2}, {"Heavy", 3}, {"Light", 1}, {"Enchanted", 4}, {"Cursed", -2}};

const std::unordered_map<std::string, int> weapon_material_bonus = {
    {"Wooden", 1},
    {"Iron", 2},
    {"Steel", 3},
    {"Mithril", 5},
    {"Adamantine", 7}};

const std::vector<std::string> weapon_types = {"Sword", "Axe", "Bow", "Dagger",
                                               "Mace"};

const std::unordered_map<std::string, std::pair<StatType, int>> suffix_bonus = {
    {"of Strength", {StatType::STR, 2}},
    {"of Agility", {StatType::DEX, 2}},
    {"of Health", {StatType::CON, 2}}};

std::unique_ptr<Item> LootGenerator::generate_item(int dungeon_level) {
  return generate_weapon(dungeon_level);
}

std::unique_ptr<Weapon> LootGenerator::generate_weapon(int dungeon_level) {
  std::string prefix = random_weapon_prefix();
  std::string material = random_weapon_material();
  std::string type = random_weapon_type();
  std::string name = prefix + " " + material + " " + type;

  int base_damage = RNG::range(5, 10) + dungeon_level * 2;
  int prefix_bonus = weapon_prefix_bonus.at(prefix);
  int material_bonus = weapon_material_bonus.at(material);
  int total_damage = base_damage + prefix_bonus + material_bonus;

  std::unordered_map<StatType, int> stat_bonuses;
  if (RNG::roll_chance(0.3)) {
    std::string suffix = random_suffix();
    name += " " + suffix;
    auto [stat, bonus] = suffix_bonus.at(suffix);
    stat_bonuses[stat] = bonus;
  }

  return std::make_unique<Weapon>(name, stat_bonuses, total_damage);
}

std::string LootGenerator::random_weapon_prefix() {
  int index = RNG::range(0, static_cast<int>(weapon_prefix_bonus.size()) - 1);
  auto it = weapon_prefix_bonus.begin();
  std::advance(it, index);
  return it->first;
}

std::string LootGenerator::random_weapon_material() {
  int index = RNG::range(0, static_cast<int>(weapon_material_bonus.size()) - 1);
  auto it = weapon_material_bonus.begin();
  std::advance(it, index);
  return it->first;
}

std::string LootGenerator::random_weapon_type() {
  int index = RNG::range(0, static_cast<int>(weapon_types.size()) - 1);
  return weapon_types[index];
}

std::string LootGenerator::random_suffix() {
  int index = RNG::range(0, static_cast<int>(suffix_bonus.size()) - 1);
  auto it = suffix_bonus.begin();
  std::advance(it, index);
  return it->first;
}
