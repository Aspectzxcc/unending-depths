#include "model/Room.hpp"
#include "model/Stats.hpp"
#include "util/Console.hpp"
#include "util/RNG.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Room::Room() {
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

void Room::run(Player &player) {
  std::string command;

  while (true) {
    Console::clear_screen();
    std::cout << "You are in a room." << std::endl;
    if (looked)
      look();
    std::cout << "Enter command (look/attack/exit): ";
    std::getline(std::cin, command);

    if (command == "look") {
      if (looked) {
        std::cout << "You have already looked around." << std::endl;
      } else {
        look();
        looked = true;
      }
      Console::wait_for_keypress();
    } else if (command == "attack") {
      if (enemies.empty()) {
        std::cout << "No enemies to attack." << std::endl;
      } else {
        std::cout << "Attacking the first enemy: " << enemies[0].get_name()
                  << std::endl;
        player.attack(enemies[0]);
        if (enemies[0].get_stats().hp <= 0) {
          std::cout << "Enemy defeated!" << std::endl;
          enemies.erase(enemies.begin());
        } else {
          std::cout << "Enemy HP is now: " << enemies[0].get_stats().hp
                    << std::endl;
        }
      }
      Console::wait_for_keypress();
    } else if (command == "exit") {
      std::cout << "Exiting the room." << std::endl;
      return;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}

void Room::look() {
  if (enemies.empty()) {
    std::cout << "No enemies in the room." << std::endl;
  } else {
    std::cout << "Enemies in the room:" << std::endl;
    for (const auto &enemy : enemies) {
      std::cout << "- " << enemy.get_name() << " (HP: " << enemy.get_stats().hp
                << ")" << std::endl;
    }
  }

  if (loot.empty()) {
    std::cout << "No loot in the room." << std::endl;
  } else {
    std::cout << "Loot in the room:" << std::endl;
    for (const auto &item : loot) {
      std::cout << "- " << item.get_name() << std::endl;
    }
  }
}
