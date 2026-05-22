#pragma once

#include <memory>

#include "../ui/include/window.hpp"
#include "common.hpp"
#include "entity.hpp"
#include "keybinds.hpp"
#include "map.hpp"
#include "player.hpp"
#include "raylib.h"
#include "renderer.hpp"

enum class GameState
{
  MainMenu,
  Playing,
  Pause,
  Dialogue,
  Transition
};

class Game
{
public:
  Game();
  void run();

private:
  GameState m_state = GameState::Playing;
  Texture2D filip;
  std::unique_ptr<Window> m_game_window;
  std::unique_ptr<Player> m_player;
  std::unique_ptr<InputManager> m_input;
  std::unique_ptr<Map> m_map;
  std::unique_ptr<Renderer> m_renderer;
};
