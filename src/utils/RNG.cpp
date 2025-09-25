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

std::size_t RNG::range(std::size_t min, std::size_t max) {
  std::uniform_int_distribution<std::size_t> dist(min, max);
  return dist(get_engine());
}
