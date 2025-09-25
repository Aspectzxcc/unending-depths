#include "view/DungeonView.hpp"
#include "view/RoomView.hpp"
#include <iostream>

DungeonView::DungeonView(Dungeon &dungeon) : BaseView<Dungeon>(dungeon) {
  commands["descend"] = [this]() { descend(); };
  commands["exit"] = [this]() { exit(); };
}

void DungeonView::render() {
  std::cout << "You are at dungeon level " << model.get_current_level_index()
            << std::endl;
  std::cout << "Enter command (descend/exit): ";
}

void DungeonView::descend() {
  if (!model.descend()) {
    std::cout << "You have reached the bottom!" << std::endl;
    Console::wait_for_keypress();
    return;
  }

  RoomView room_view(model.get_current_level().get_current_room(),
                     model.get_current_level());
  room_view.display();
}

void DungeonView::exit() {
  std::cout << "Exiting dungeon." << std::endl;
  running = false;
}
