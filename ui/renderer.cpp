#include "renderer.hpp"

#include "constants.hpp"
#include "raylib.h"

#define SPRITE_SIZE 32

Renderer::Renderer()
{
  tileset_ = LoadTexture("sprites/spritesheet.png");
  player_sprite_ = LoadTexture("sprites/ja.png");
}

Renderer::~Renderer()
{
  UnloadTexture(tileset_);
  UnloadTexture(player_sprite_);
}

void Renderer::drawPlayer(const Player& player) {
    DrawTexture(player_sprite_, player.getX(), player.getY(), RAYWHITE);
}

void Renderer::drawMap(const Map& map)
{
  for (size_t y = 0; y < map.getRows(); y++) {
    for (size_t x = 0; x < map.getCols(); x++) {
      Tile tile = map.getTile(x, y);
      Vector2 pos = {(float)x * TILE_SIZE, (float)y * TILE_SIZE};
      DrawTextureRec(tileset_, getTileRect(tile.floor), pos, WHITE);

      // pass 2 - object on top
      if (tile.object != TileType::None) {
        DrawTextureRec(tileset_, getTileRect(tile.object), pos, WHITE);
      }
    }
  }
}

void Renderer::drawTextBox(const std::string& text) {
    DrawRectangle(
        TEXTBOX_PADDING, 
        VIRTUAL_HEIGHT - TEXTBOX_HEIGHT - TEXTBOX_PADDING,
        VIRTUAL_WIDTH - TEXTBOX_PADDING * 2, 
        TEXTBOX_HEIGHT, 
        BLACK
    );
    DrawRectangleLines(
        TEXTBOX_PADDING,
        VIRTUAL_HEIGHT - TEXTBOX_HEIGHT - TEXTBOX_PADDING,
        VIRTUAL_WIDTH - TEXTBOX_PADDING * 2,
        TEXTBOX_HEIGHT,
        WHITE
    );
    DrawText(
        text.c_str(),
        TEXTBOX_PADDING * 2,
        VIRTUAL_HEIGHT - TEXTBOX_HEIGHT + TEXTBOX_TEXT_OFFSET - TEXTBOX_PADDING,
        TEXTBOX_FONT_SIZE,
        WHITE
    );
}
