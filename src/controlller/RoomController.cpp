#include "controller/RoomController.hpp"
#include <iostream>

void RoomController::run(Room &room, RoomView &roomView, Player &player) {
  std::string command;

  while (true) {
    roomView.display(room);
    std::getline(std::cin, command);

    if (command == "look") {
      roomView.display_look(room);
    } else if (command == "attack") {
      bool enemy_present = !room.get_enemies().empty();
      int enemy_hp = 0;

      if (enemy_present) {
        player.attack(room.get_enemy(0));
        enemy_hp = room.get_enemy(0).get_stats().at(StatType::HP);

        if (enemy_hp <= 0) {
          room.remove_enemy(0);
        }
      }

      roomView.display_attack(enemy_present, enemy_hp);
    } else if (command == "take") {
      bool item_present = !room.get_loot().empty();

      if (item_present) {
        player.add_item(room.take_loot(0));
      }
    } else if (command == "exit") {
      return;
    } else {
      roomView.display_message("Invalid command.");
    }
  }
}
