#pragma once

#include "common.hpp"
#include "map.hpp"
#include "window.hpp"
#include "tile_defs.hpp"
#include "player.hpp"

class Renderer
{
public:
  Renderer();
  ~Renderer();
  void drawMap(const Map& map);
  void drawPlayer(const Player& player);

  void drawTextBox(const std::string& text);

private:
  Texture2D tileset_;
  Texture2D player_sprite_;
};
