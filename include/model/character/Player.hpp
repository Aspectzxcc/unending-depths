#pragma once
#include "Character.hpp"
#include "model/item/Item.hpp"
#include <memory>
#include <vector>

class Player : public Character {
public:
  Player(const Stats &stats, const std::string &name);
  const std::vector<std::unique_ptr<Item>> &get_inventory() const;
  void add_item(std::unique_ptr<Item> item);
  void remove_item(size_t index);

private:
  std::vector<std::unique_ptr<Item>> inventory;
};
