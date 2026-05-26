#include <cstdlib>
#include <memory>

#include "game.hpp"

#include "constants.hpp"
#include "dialogue.hpp"
#include "input_manager.hpp"
#include "map.hpp"
#include "renderer.hpp"
#include "text.hpp"

using namespace Dialogue;

Game::Game()
{
  m_input = std::make_unique<InputManager>();
  m_game_window = std::make_unique<Window>();
  m_player = std::make_unique<Player>("filip");
  m_map = std::make_unique<Map>(Map::loadFromFile("sprites/interview_room.tmj"));
  m_renderer = std::make_unique<Renderer>();
  m_text = std::make_unique<Text>(main_menu, TEXT_SPEED_SLOW, FONT_SIZE_BIG);
  m_text_helper = std::make_unique<Text>(
      main_menu_helper, TEXT_SPEED_INSTANT, FONT_SIZE_SMALL);

  m_input->bind(KEY_F10, [this] { m_game_window->toggleFullscreen(); });
  m_input->bind(KEY_W, [this] { m_player->setDirection(Direction::Up); });
  m_input->bind(KEY_S, [this] { m_player->setDirection(Direction::Down); });
  m_input->bind(KEY_A, [this] { m_player->setDirection(Direction::Left); });
  m_input->bind(KEY_D, [this] { m_player->setDirection(Direction::Right); });
  m_input->bind(KEY_SPACE, [this] { skipDialogue(); });
}

void Game::run()
{
  while (!m_game_window->shouldClose()) {
    m_input->update();
    m_game_window->beginFrame();
    ClearBackground(BLACK);

    switch (m_state) {
      case GameState::MainMenu:
        // calculate new state
        m_text->update();
        m_text_helper->update();
        m_renderer->drawMainMenu(*m_text, *m_text_helper);

        if (m_renderer->isPlayClicked(GetMousePosition(),
                                      IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
          m_state = GameState::Transition;
          m_text = std::make_unique<Text>(chapter00);
        }

        if (m_renderer->isExitClicked(GetMousePosition(),
                                      IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
          return;
        }

        break;
      case GameState::Transition:
        m_text->update();
        m_renderer->drawTransition(*m_text, *m_text_helper);
        if (m_text->isDone()) {
          m_state = GameState::Playing;
        }

        break;
      case GameState::Playing:
        m_player->update();
        m_renderer->drawMap(*m_map);

        if (m_map->isWalkable(m_player->getNextX() / TILE_SIZE,
                              m_player->getNextY() / TILE_SIZE))
        {
          m_player->confirmMove();
        }
        m_renderer->drawPlayer(*m_player);
        break;

      default:
        break;
    }

    m_game_window->endFrame();
  }
}

void Game::skipDialogue()
{
  m_text->skip();
}
