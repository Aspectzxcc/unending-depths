#include "model/Item.hpp"

Item::Item(const std::string &name) : name(name) {}

// getters
const std::string &Item::get_name() const { return name; }
