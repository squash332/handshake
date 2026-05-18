#include "keybinds.hpp"

void registerKeybinds(InputManager& input, Window& window, Player& player) {
    input.bind(KEY_F10, [&] {window.toggleFullscreen();});
    input.bind(KEY_F11, [&]{window.toggleWindowed();});
}