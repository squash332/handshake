#include <memory>

#include "game.hpp"

#include "map.hpp"
#include "renderer.hpp"

Game::Game()
{
  m_input = std::make_unique<InputManager>();
  m_game_window = std::make_unique<Window>();
  m_player = std::make_unique<Player>();
  m_map = std::make_unique<Map>(Map::createOffice());
  m_renderer = std::make_unique<Renderer>();
  registerKeybinds(*m_input, *m_game_window, *m_player);
}

void Game::run()
{
  while (!m_game_window->shouldClose()) {
    m_input->update();  // our keybinds manager

    m_game_window->beginFrame();  // initiliaze render texture for drawing

    ClearBackground(LIGHTGRAY);
    m_renderer->drawMap(*m_map);

    m_game_window->endFrame();  // end drawing
  }
}
