#pragma once

#include <memory>

#include "common.hpp"
#include "constants.hpp"
#include "entity.hpp"
#include "input_manager.hpp"
#include "map.hpp"
#include "player.hpp"
#include "raylib.h"
#include "renderer.hpp"
#include "text.hpp"
#include "window.hpp"

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
  void skipDialogue();

private:
  GameState m_state = GameState::MainMenu;
  Texture2D filip;

  std::unique_ptr<Window> m_game_window;
  std::unique_ptr<Player> m_player;
  std::unique_ptr<InputManager> m_input;
  std::unique_ptr<Map> m_map;
  std::unique_ptr<Renderer> m_renderer;
  std::unique_ptr<Text> m_text;
  std::unique_ptr<Text> m_text_helper;
};
