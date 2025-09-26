#include "model/character/Player.hpp"

Player::Player(const std::unordered_map<StatType, int> &stats,
               const std::string &name)
    : Character(stats, name), equipped_weapon(nullptr) {}

void Player::attack(Character &target) {
  if (equipped_weapon) {
    int weapon_damage = equipped_weapon->get_damage();
    int player_strength = this->get_stats().at(StatType::STR);
    int total_damage = (weapon_damage + player_strength) -
                       target.get_stats().at(StatType::CON);
    int target_health =
        std::max(0, target.get_stats().at(StatType::HP) - total_damage);

    target.modify_stat(StatType::HP, target_health);
  } else {
    int damage = this->get_stats().at(StatType::STR) -
                 target.get_stats().at(StatType::CON);

    int target_health =
        std::max(0, target.get_stats().at(StatType::HP) - damage);

    target.modify_stat(StatType::HP, target_health);
  }
}
const std::vector<std::unique_ptr<Item>> &Player::get_inventory() const {
  return inventory;
}

void Player::add_item(std::unique_ptr<Item> item) {
  inventory.push_back(std::move(item));
}

void Player::remove_item(size_t index) {
  if (index < inventory.size()) {
    inventory.erase(inventory.begin() + index);
  }
}
