#include "Room.hpp"
#include "Console.hpp"
#include "RNG.hpp"
#include "Stats.hpp"
#include <iostream>
#include <string>

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
  std::string command;
  bool in_room = true;

  while (in_room) {
    Console::clear_screen();
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

    std::cout << "Enter command (search/exit): ";
    std::getline(std::cin, command);

    if (command == "look") {
      std::cout << "You look around the room." << std::endl;
      if (enemies.empty() && loot.empty()) {
        std::cout << "The room is empty." << std::endl;
      }
      Console::wait_for_keypress();
    } else if (command == "exit") {
      std::cout << "Exiting room." << std::endl;
      in_room = false;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }
}
