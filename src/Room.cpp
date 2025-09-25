#include "Room.hpp"
#include "Stats.hpp"
#include <iostream>

Room::Room() {
  // Initialize room with some enemies and loot (placeholder)
  enemies.emplace_back(Stats{30, 15, 10, 10}, "Goblin");
  enemies.emplace_back(Stats{20, 10, 5, 10}, "Orc");
  loot.emplace_back("Health Potion");
  loot.emplace_back("Sword");
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
