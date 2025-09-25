#pragma once
#include "model/Dungeon.hpp"
#include "view/BaseView.hpp"

class DungeonView : public BaseView<Dungeon> {
public:
  DungeonView(Dungeon &dungeon);

protected:
  void render() override;

private:
  void descend();
  void exit();
};
