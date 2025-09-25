#pragma once
#include <cstddef>
#include <random>

class RNG {
public:
  static bool roll_chance(double probability);
  static int range(int min, int max);
  static std::size_t range(std::size_t min, std::size_t max);

private:
  static std::mt19937 &get_engine(); // single shared generator
};
