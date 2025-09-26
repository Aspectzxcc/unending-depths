#include "view/RoomView.hpp"
#include "model/character/StatType.hpp"
#include "util/Console.hpp"
#include <iostream>

void RoomView::display(Room &room) {
  Console::clear_screen();
  std::cout << "You are in a room." << std::endl;

  if (looked) {
    display_enemies(room);
    display_loot(room);
  }

  std::cout << "Available commands: look, attack, exit" << std::endl;
}

void RoomView::display_look(Room &room) {
  if (looked) {
    std::cout << "You have already looked around." << std::endl;
  } else {
    display_enemies(room);
    display_loot(room);
    looked = true;
  }
  Console::wait_for_keypress();
}

void RoomView::display_attack(bool enemy_present, int enemy_hp) {
  if (!enemy_present) {
    std::cout << "No enemies to attack." << std::endl;
    Console::wait_for_keypress();
    return;
  }

  std::cout << "Attacking the first enemy." << std::endl;

  if (enemy_hp <= 0) {
    std::cout << "Enemy defeated!" << std::endl;
    Console::wait_for_keypress();
    return;
  }

  std::cout << "Enemy HP is now: " << enemy_hp << std::endl;
  Console::wait_for_keypress();
}

void RoomView::display_message(const std::string &message) {
  std::cout << message << std::endl;
}

void RoomView::display_enemies(Room &room) {
  const auto &enemies = room.get_enemies();
  if (enemies.empty()) {
    std::cout << "No enemies in the room." << std::endl;
  } else {
    std::cout << "Enemies in the room:" << std::endl;
    for (const auto &enemy : enemies) {
      std::cout << "- " << enemy.get_name()
                << " (HP: " << enemy.get_stats().at(StatType::HP) << ")"
                << std::endl;
    }
  }
}

void RoomView::display_loot(Room &room) {
  const auto &loot = room.get_loot();
  if (loot.empty()) {
    std::cout << "No loot in the room." << std::endl;
  } else {
    std::cout << "Loot in the room:" << std::endl;
    for (const auto &item : loot) {
      std::cout << "- " << item.get_name() << std::endl;
    }
  }
}
