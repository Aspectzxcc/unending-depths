#pragma once
#include <cstddef>
#include <random>
#include <utility>
#include <vector>

class RNG {
public:
  static bool roll_chance(double probability);
  static int range(int min, int max);
  static std::size_t range(std::size_t min, std::size_t max);

  template <typename T>
  static T weighted_choice(const std::vector<std::pair<T, double>> &items) {
    double total_weight = 0.0;
    for (const auto &item : items) {
      total_weight += item.second;
    }

    std::uniform_real_distribution<double> dist(0.0, total_weight);
    double random_value = dist(get_engine());

    for (const auto &item : items) {
      if (random_value < item.second) {
        return item.first;
      }
      random_value -= item.second;
    }

    // fallback in case of rounding errors
    return items.back().first;
  }

private:
  static std::mt19937 &get_engine(); // single shared generator
};
