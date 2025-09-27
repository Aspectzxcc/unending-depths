#include "util/LootGenerator.hpp"
#include "model/character/StatType.hpp"
#include "model/item/modifier/StatModifier.hpp"
#include "util/RNG.hpp"
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, int> weapon_prefix_bonus = {
    {"Rusty", 0},     // barely adds damage, very common
    {"Sharp", 2},     // common physical boost
    {"Heavy", 3},     // slightly rarer, more STR scaling
    {"Balanced", 2},  // neutral, slightly uncommon
    {"Enchanted", 5}, // rare, magical power
    {"Cursed", -2},   // rare, negative effect, fun rogue-like twist
    {"Legendary", 7}  // very rare, top-tier prefix
};

const std::vector<std::pair<std::string, double>> weapon_prefix_weights = {
    {"Rusty", 0.30},    {"Sharp", 0.25},     {"Heavy", 0.20},
    {"Balanced", 0.15}, {"Enchanted", 0.06}, {"Cursed", 0.03},
    {"Legendary", 0.01}};

const std::unordered_map<std::string, int> weapon_material_bonus = {
    {"Wooden", 1},     {"Iron", 2},       {"Steel", 3}, {"Mithril", 5},
    {"Adamantine", 7}, {"Dragonbone", 10} // extremely rare, endgame-tier
};

const std::vector<std::pair<std::string, double>> weapon_material_weights = {
    {"Wooden", 0.30},  {"Iron", 0.30},       {"Steel", 0.20},
    {"Mithril", 0.12}, {"Adamantine", 0.07}, {"Dragonbone", 0.01}};

const std::vector<std::string> weapon_types = {"Sword",  "Axe",  "Bow",
                                               "Dagger", "Mace", "Spear"};

const std::vector<std::pair<std::string, double>> weapon_type_weights = {
    {"Sword", 0.25}, {"Axe", 0.20},  {"Bow", 0.20}, {"Dagger", 0.15},
    {"Mace", 0.15},  {"Spear", 0.05} // rare, specialized weapon
};

std::unordered_map<std::string, StatModifier> suffix_bonus = {
    {"of Strength", StatModifier(StatType::STR, 2)},
    {"of Agility", StatModifier(StatType::DEX, 2)},
    {"of Vitality", StatModifier(StatType::CON, 2)},
    {"of the Phoenix", StatModifier(StatType::HP, 10)}, // rare, big HP bonus
    {"of Precision",
     StatModifier(StatType::DEX, 4)},             // rare, powerful dex bonus
    {"of Titans", StatModifier(StatType::STR, 5)} // extremely rare
};

const std::vector<std::pair<std::string, double>> suffix_weights = {
    {"of Strength", 0.35},    {"of Agility", 0.30},   {"of Vitality", 0.25},
    {"of the Phoenix", 0.05}, {"of Precision", 0.03}, {"of Titans", 0.02}};

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

  std::vector<StatModifier> stat_bonuses;

  if (RNG::roll_chance(0.3)) {
    std::string suffix = random_suffix();
    name += " " + suffix;
    stat_bonuses.push_back(suffix_bonus.at(suffix));
  }

  return std::make_unique<Weapon>(name, stat_bonuses, total_damage);
}

std::string LootGenerator::random_weapon_prefix() {
  return RNG::weighted_choice(weapon_prefix_weights);
}

std::string LootGenerator::random_weapon_material() {
  return RNG::weighted_choice(weapon_material_weights);
}

std::string LootGenerator::random_weapon_type() {
  return RNG::weighted_choice(weapon_type_weights);
}

std::string LootGenerator::random_suffix() {
  return RNG::weighted_choice(suffix_weights);
}
