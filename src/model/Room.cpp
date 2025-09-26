#include "model/Room.hpp"
#include "model/Stats.hpp"
#include "util/RNG.hpp"
#include <cstddef>

void Room::generate() {
  if (RNG::roll_chance(0.5)) {
    std::size_t MIN_NUM_ENEMIES = 1;
    std::size_t MAX_NUM_ENEMIES = 3;
    std::size_t spawned_enemies_count =
        RNG::range(MIN_NUM_ENEMIES, MAX_NUM_ENEMIES);

    for (std::size_t i = 1; i <= spawned_enemies_count; ++i) {
      enemies.emplace_back(Stats{25, 12, 8, 10}, "Skeleton");
    }
  }

  if (RNG::roll_chance(0.3)) {
    std::size_t MIN_NUM_LOOT = 1;
    std::size_t MAX_NUM_LOOT = 5;
    std::size_t spawned_loot_count = RNG::range(MIN_NUM_LOOT, MAX_NUM_LOOT);

    for (std::size_t i = 1; i <= spawned_loot_count; ++i) {
      loot.emplace_back("Health Potion");
    }
  }
}

// getters
const std::vector<Enemy> &Room::get_enemies() const { return enemies; }
const std::vector<Item> &Room::get_loot() const { return loot; }
Enemy &Room::get_enemy(int index) { return enemies.at(index); }

// setters
void Room::remove_enemy(int index) { enemies.erase(enemies.begin() + index); }
