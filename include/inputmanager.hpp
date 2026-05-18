#pragma once

#include <functional>
#include <unordered_map>

#include "common.hpp"
#include "raylib.h"

class InputManager
{
public:
  void bind(int key, std::function<void()>);
  void update();

private:
  std::unordered_map<int, std::function<void()>> keybinds_;
};
