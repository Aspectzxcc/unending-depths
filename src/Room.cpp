#include "Room.hpp"
#include "RNG.hpp"
#include "Stats.hpp"
#include <iostream>

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

void Room::display() {
  std::cout << "You have entered a room." << std::endl;
  std::cout << "Enemies in the room:" << std::endl;
  for (const auto &enemy : enemies) {
    std::cout << "- " << enemy.get_name() << " (HP: " << enemy.get_stats().hp
              << ")" << std::endl;
  }
  std::cout << "Loot in the room:" << std::endl;
  for (const auto &item : loot) {
    std::cout << "- " << item.get_name() << std::endl;
  }
}
