#pragma once
#include "model/character/StatType.hpp"

struct StatModifier {
  StatModifier(StatType s, int v) : stat(s), value(v) {}
  StatType stat;
  int value;
};
