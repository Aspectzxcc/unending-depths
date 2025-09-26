#include "model/Room.hpp"
#include <cstddef>

Room::Room(std::vector<Enemy> enemies, std::vector<std::unique_ptr<Item>> loot)
    : enemies(std::move(enemies)), loot(std::move(loot)) {}

// getters
const std::vector<Enemy> &Room::get_enemies() const { return enemies; }

const std::vector<std::unique_ptr<Item>> &Room::get_loot() const {
  return loot;
}

Enemy &Room::get_enemy(int index) { return enemies.at(index); }

// setters
void Room::remove_enemy(int index) { enemies.erase(enemies.begin() + index); }
