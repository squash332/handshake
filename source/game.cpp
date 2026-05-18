#include "../include/game.hpp"

Game::Game()
{
  input_ = std::make_unique<InputManager>();
  game_window_ = std::make_unique<Window>();
  player_ = std::make_unique<Player>();
  registerKeybinds(*input_, *game_window_, *player_);
}

void Game::run()
{
  Texture2D filip = LoadTexture("sprites/ja.png");
  Texture2D floor_tile = LoadTexture("sprites/floor_sprite.png");

  while (!game_window_->shouldClose()) {
    input_->update();

    game_window_->beginFrame();
    ClearBackground(LIGHTGRAY);
    DrawTexture(filip, 10, 10, RAYWHITE);
    game_window_->endFrame();
  }
}
