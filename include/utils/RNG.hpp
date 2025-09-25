#pragma once
#include <random>

class RNG {
public:
  static bool roll_chance(double probability);
  static int range(int min, int max);

private:
  static std::mt19937 &get_engine(); // single shared generator
};
