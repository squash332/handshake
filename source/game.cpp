#include <memory>
#include "game.hpp"
#include "map.hpp"
#include "map_renderer.hpp"

Game::Game()
{
  m_input = std::make_unique<InputManager>();
  m_game_window = std::make_unique<Window>();
  m_player = std::make_unique<Player>();
  m_map = std::make_unique<Map>();
  m_map_renderer = std::make_unique<MapRenderer>(*m_map);
  registerKeybinds(*m_input, *m_game_window, *m_player);
}

void Game::run()
{
  Texture2D filip = LoadTexture("sprites/ja.png");

  while (!m_game_window->shouldClose()) {
    m_input->update();

    m_game_window->beginFrame();
    ClearBackground(LIGHTGRAY);
    m_map_renderer->draw();
    DrawTexture(filip, 10, 10, RAYWHITE);
    m_game_window->endFrame();
  }
}
