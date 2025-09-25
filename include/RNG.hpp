#pragma once
#include <random>

class RNG {
public:
  // call once at program start (e.g., in main)
  static void init();

  // returns true with probability in [0.0, 1.0]
  static bool roll_chance(double probability);

private:
  static inline std::mt19937 rng;
};
