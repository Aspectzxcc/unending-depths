#pragma once
#include <string>

class Item {
public:
  Item(const std::string &name);
  const std::string &get_name() const;

private:
  std::string name;
};
