#include "renderer.hpp"

#include "constants.hpp"
#include "raylib.h"

#define SPRITE_SIZE 32

Renderer::Renderer()
{
  tileset_ = LoadTexture("sprites/spritesheet.png");
  player_sprite_ = LoadTexture("sprites/ja.png");
  buttons_ = LoadTexture("sprites/play_btn.png");
}

Renderer::~Renderer()
{
  UnloadTexture(tileset_);
  UnloadTexture(player_sprite_);
  UnloadTexture(buttons_);
}

void Renderer::drawPlayer(const Player& player)
{
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

void Renderer::drawText(const char* text,
                        int charsShown,
                        TextPosition pos,
                        int fontSize)
{
  int textWidth = MeasureText(text, fontSize);
  int posX = (VIRTUAL_WIDTH / 2) - (textWidth / 2);
  int posY;

  switch (pos) {
    case TextPosition::TopMiddle:
      posY = TEXT_TOP_MIDDLE_Y;
      break;
    case TextPosition::Middle:
      posY = TEXT_MIDDLE_Y - (fontSize / 2);
      break;
    case TextPosition::BottomMiddle:
      posY = TEXT_BOTTOM_Y;
      break;
    case TextPosition::DialogueBox:
      posX = TEXTBOX_PADDING * 2;
      posY = TEXT_DIALOGUE_Y;
      break;
  }

  DrawText(TextSubtext(text, 0, charsShown), posX, posY, fontSize, WHITE);
}

void Renderer::drawTextBox(const std::string& text)
{
  DrawRectangle(TEXTBOX_PADDING,
                VIRTUAL_HEIGHT - TEXTBOX_HEIGHT - TEXTBOX_PADDING,
                VIRTUAL_WIDTH - TEXTBOX_PADDING * 2,
                TEXTBOX_HEIGHT,
                BLACK);
  DrawRectangleLines(TEXTBOX_PADDING,
                     VIRTUAL_HEIGHT - TEXTBOX_HEIGHT - TEXTBOX_PADDING,
                     VIRTUAL_WIDTH - TEXTBOX_PADDING * 2,
                     TEXTBOX_HEIGHT,
                     WHITE);
  DrawText(
      text.c_str(),
      TEXTBOX_PADDING * 2,
      VIRTUAL_HEIGHT - TEXTBOX_HEIGHT + TEXTBOX_TEXT_OFFSET - TEXTBOX_PADDING,
      TEXTBOX_FONT_SIZE,
      WHITE);
}

void Renderer::drawMainMenu(const Text& text, const Text& text_helper)
{
  // render state
  drawText(text.getText(), text.charsShown(), TextPosition::TopMiddle);
  drawText(text_helper.getText(),
           text_helper.charsShown(),
           TextPosition::BottomMiddle,
           FONT_SIZE_SMALL);
  DrawTexture(buttons_,
              (VIRTUAL_WIDTH / 2) - BUTTON_WIDTH / 2,
              (VIRTUAL_HEIGHT / 2) - BUTTON_HEIGHT / 2,
              RAYWHITE);
}

bool Renderer::isPlayClicked(Vector2 mousePos, bool mousePressed)
{
  float btnX = ((float)VIRTUAL_WIDTH / 2) - (float)BUTTON_WIDTH / 2;
  float btnY = ((float)VIRTUAL_HEIGHT / 2) - (float)BUTTON_HEIGHT / 2;
  Rectangle playRec = {btnX, btnY, BUTTON_WIDTH, (float)BUTTON_HEIGHT / 2};
  return mousePressed && CheckCollisionPointRec(mousePos, playRec);
}

bool Renderer::isExitClicked(Vector2 mousePos, bool mousePressed)
{
  float btnX = ((float)VIRTUAL_WIDTH / 2) - (float)BUTTON_WIDTH / 2;
  float btnY = ((float)VIRTUAL_HEIGHT / 2) - (float)BUTTON_HEIGHT / 2;
  Rectangle exitRec = {btnX,
                       btnY + (float)BUTTON_HEIGHT / 2,
                       BUTTON_WIDTH,
                       (float)BUTTON_HEIGHT / 2};
  return mousePressed && CheckCollisionPointRec(mousePos, exitRec);
}

void Renderer::drawTransition(const Text& text, const Text& text_helper)
{
  drawText(text.getText(),
           text.charsShown(),
           TextPosition::Middle,
           text.getFontSize());

  drawText(text_helper.getText(),
           text_helper.charsShown(),
           TextPosition::BottomMiddle,
           FONT_SIZE_SMALL);
}
