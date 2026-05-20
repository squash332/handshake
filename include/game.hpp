#pragma once

#include <memory>
#include "common.hpp"
#include "entity.hpp"
#include "keybinds.hpp"
#include "map.hpp"
#include "map_renderer.hpp"
#include "player.hpp"
#include "../ui/include/window.hpp"

class Game
{
public:
  Game();
  void run();

private:
  std::unique_ptr<Window> m_game_window;
  std::unique_ptr<Player> m_player;
  std::unique_ptr<InputManager> m_input;
  std::unique_ptr<MapRenderer> m_map_renderer;
  std::unique_ptr<Map> m_map;
};
