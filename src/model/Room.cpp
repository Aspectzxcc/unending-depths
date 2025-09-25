#include "model/Room.hpp"
#include "model/Stats.hpp"
#include "utils/RNG.hpp"

Room::Room() {
  if (RNG::roll_chance(0.5)) {
    int spawned_enemies_count = RNG::range(1, 3);

    for (int i = 1; i <= spawned_enemies_count; ++i) {
      enemies.emplace_back(Stats{25, 12, 8, 10}, "Skeleton");
    }
  }

  if (RNG::roll_chance(0.3)) {
    int spawned_loot_count = RNG::range(1, 2);

    for (int i = 1; i <= spawned_loot_count; ++i) {
      loot.emplace_back("Health Potion");
    }
  }
}

// getters
const std::vector<Enemy> &Room::get_enemies() const { return enemies; }
const std::vector<Item> &Room::get_loot() const { return loot; }
