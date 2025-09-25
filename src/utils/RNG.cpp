#include "utils/RNG.hpp"

std::mt19937 &RNG::get_engine() {
  static std::mt19937 rng(std::random_device{}());
  return rng;
}

bool RNG::roll_chance(double probability) {
  std::bernoulli_distribution dist(probability);
  return dist(get_engine());
}

int RNG::range(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(get_engine());
}
