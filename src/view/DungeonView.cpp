#include "view/DungeonView.hpp"
#include "utils/Console.hpp"
#include "view/LevelView.hpp"
#include <iostream>

DungeonView::DungeonView(Dungeon &dungeon) : dungeon(dungeon) {
  commands["descend"] = [this]() { descend(); };
  commands["exit"] = [this]() { exit(); };
}

void DungeonView::display() {
  std::string command;
  bool in_dungeon = true;

  while (in_dungeon) {
    Console::clear_screen();
    if (dungeon.get_current_level_index() == 0) {
      std::cout << "You are at the entrance of the dungeon." << std::endl;
    } else {
      std::cout << "You are at level " << dungeon.get_current_level_index()
                << std::endl;
    }
    std::cout << "Enter command (descend/exit): " << std::endl;
    std::getline(std::cin, command);

    handle_command(command);
  }
}

void DungeonView::handle_command(const std::string &command) {
  auto it = commands.find(command);
  if (it != commands.end()) {
    it->second();
  } else {
    std::cout << "Invalid command." << std::endl;
  }
}

void DungeonView::descend() {
  if (dungeon.get_current_level_index() >= dungeon.get_levels().size()) {
    std::cout << "You have reached the bottom of the dungeon!" << std::endl;
    return;
  }

  std::cout << "You are descending to level "
            << dungeon.get_current_level_index() + 1 << std::endl;
  LevelView level_view(
      *dungeon.get_levels()[dungeon.get_current_level_index()]);
  level_view.display();

  dungeon.increment_current_level_index();
}

void DungeonView::exit() {
  std::cout << "Exiting dungeon." << std::endl;
  // break loop by exception to signal exit
  throw std::runtime_error("Exit Dungeon");
}
