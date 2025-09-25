#include "RNG.hpp"

void RNG::init() {
  static bool initialized = false;
  if (!initialized) {
    rng.seed(std::random_device{}());
    initialized = true;
  }
}

bool RNG::roll_chance(double probability) {
  std::bernoulli_distribution dist(probability);
  return dist(rng);
}
