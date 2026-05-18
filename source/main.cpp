#include "game.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "map.hpp"
#include "window.hpp"
#include "keybinds.hpp"

int main()
{
  std::unique_ptr<InputManager> input = std::make_unique<InputManager>();
  std::unique_ptr<Window> game_window = std::make_unique<Window>();
  std::unique_ptr<Player> player = std::make_unique<Player>();
  std:: cout << "player health:" << player->health_ << std::endl;
  Texture2D filip = LoadTexture("sprites/ja.png");
  Texture2D floor_tile = LoadTexture("sprites/floor_sprite.png");

  registerKeybinds(*input, *game_window, *player);

  while(!game_window->shouldClose()) {
    input->update();
    
    game_window->beginFrame();
    ClearBackground(LIGHTGRAY);
    DrawTexture(filip, 10, 10, RAYWHITE);
    game_window->endFrame();

  }

  return 0;
}
