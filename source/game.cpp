#include <memory>
#include "game.hpp"
#include "map.hpp"
#include "map_renderer.hpp"

Game::Game()
{
  m_input = std::make_unique<InputManager>();
  m_game_window = std::make_unique<Window>();
  filip = LoadTexture("sprites/ja.png");
  m_player = std::make_unique<Player>();
  m_map = std::make_unique<Map>(Map::createOffice());
  m_map_renderer = std::make_unique<MapRenderer>(*m_map);
  registerKeybinds(*m_input, *m_game_window, *m_player);
}

void Game::run()
{
  while (!m_game_window->shouldClose()) {
    m_input->update();

    m_game_window->beginFrame();
    ClearBackground(LIGHTGRAY);
    m_map_renderer->draw();
    DrawTexture(filip, 0, 0, RAYWHITE);
    m_game_window->endFrame();
  }
}
