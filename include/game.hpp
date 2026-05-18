#pragma once

#include "common.hpp"
#include "entity.hpp"
#include "keybinds.hpp"
#include "map.hpp"
#include "player.hpp"
#include "window.hpp"

class Game
{
public:
  Game();
  void run();

private:
  std::unique_ptr<Window> game_window_;
  std::unique_ptr<Player> player_;
  std::unique_ptr<InputManager> input_;
};
