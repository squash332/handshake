#include "keybinds.hpp"

void registerKeybinds(InputManager& input, Window& window, Player& player)
{
  input.bind(KEY_F10, [&] { window.toggleFullscreen(); });
  input.bind(KEY_F11, [&] { window.toggleWindowed(); });
  input.bind(KEY_W, [&] { player.setDirection((Direction::Up)); });
  input.bind(KEY_S, [&]() { player.setDirection(Direction::Down); });
  input.bind(KEY_A, [&]() { player.setDirection(Direction::Left); });
  input.bind(KEY_D, [&]() { player.setDirection(Direction::Right); });
}
