#pragma once
#include "model/Level.hpp"
#include "model/Room.hpp"
#include "view/BaseView.hpp"

class RoomView : public BaseView<Room> {
public:
  RoomView(Room &room, Level &level);
  void render() override;

private:
  Level &level;
  bool looked = false;
  void go(const std::string &direction);
  void look();
  void exit();
};
