#pragma once

#include "common.hpp"
#include "constants.hpp"
#include "map.hpp"
#include "player.hpp"
#include "text.hpp"
#include "tile_defs.hpp"
#include "window.hpp"

enum class TextPosition
{
  TopMiddle,
  Middle,
  BottomMiddle,
  DialogueBox
};

class Renderer
{
public:
  Renderer();
  ~Renderer();
  void drawMainMenu(const Text& text, const Text& text_helper);
  void drawTransition(const Text& text, const Text& text_helper);

  void drawMap(const Map& map);
  void drawPlayer(const Player& player);

  void drawText(const char* text,
                int charsShown,
                TextPosition pos = TextPosition::Middle,
                int fontSize = FONT_SIZE_MEDIUM);
  void drawTextBox(const std::string& text);

  bool isPlayClicked(Vector2 mousePos, bool mousePressed);
  bool isExitClicked(Vector2 mousePos, bool mousePressed);

private:
  Texture2D tileset_;
  Texture2D player_sprite_;
  Texture2D buttons_;
};
