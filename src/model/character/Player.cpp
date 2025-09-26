#include "model/character/Player.hpp"

Player::Player(const Stats &stats, const std::string &name)
    : Character(stats, name) {}

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
