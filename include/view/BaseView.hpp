#pragma once
#include "utils/Console.hpp"
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

template <typename T> class BaseView {
public:
  BaseView(T &model) : model(model) {}
  virtual ~BaseView() = default;

  void display() {
    running = true;
    while (running) {
      Console::clear_screen();
      render();
      std::string command;
      std::getline(std::cin, command);
      handle_command(command);
    }
  }

protected:
  T &model;
  std::unordered_map<std::string, std::function<void()>> commands;
  bool running = true;

  virtual void render() = 0;

  virtual void handle_command(const std::string &command) {
    auto it = commands.find(command);
    if (it != commands.end()) {
      it->second();
    } else {
      std::cout << "Invalid command." << std::endl;
      Console::wait_for_keypress();
    }
  }
};
