#include <memory>

#include "game.hpp"

#include "constants.hpp"
#include "input_manager.hpp"
#include "map.hpp"
#include "renderer.hpp"
#include "text.hpp"

Game::Game()
{
  m_input = std::make_unique<InputManager>();
  m_game_window = std::make_unique<Window>();
  m_player = std::make_unique<Player>("filip");
  m_map = std::make_unique<Map>(Map::createOffice());
  m_renderer = std::make_unique<Renderer>();
  m_text = std::make_unique<Text>("Chapter-00");
  m_text_helper = std::make_unique<Text>(
      "press [space] to speed up dialogue", TEXT_SPEED_INSTANT, FONT_SIZE_SMALL);

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
    m_player->update();

    if (m_map->isWalkable(m_player->getNextX() / TILE_SIZE,
                          m_player->getNextY() / TILE_SIZE))
    {
      m_player->confirmMove();
    }

    m_game_window->beginFrame();
    ClearBackground(BLACK);

    switch (m_state) {
      case GameState::MainMenu:
        // calculate new state
        m_text->update();
        m_text_helper->update();

        // render state
        m_renderer->drawText(m_text->getText(), m_text->charsShown());
        m_renderer->drawText(m_text_helper->getText(),
                             m_text_helper->charsShown(),
                             TextPosition::BottomMiddle,
                             FONT_SIZE_SMALL);
        // if (m_text->isDone()) {
        //   m_state = GameState::Playing;
        // }
        break;
      case GameState::Playing:
        m_renderer->drawMap(*m_map);
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
