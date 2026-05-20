#include "map_renderer.hpp"

#include "constants.hpp"
#include "raylib.h"

// so we have a 2d array [][], need to traverse our window, fill in with the
// tile types write movement for character

MapRenderer::MapRenderer(const Map& map)
    : map_(map)
{
  tileset_ = LoadTexture("../sprites/spritesheet.png");
}

MapRenderer::~MapRenderer()
{
  UnloadTexture(tileset_);
}

void MapRenderer::draw()
{
  for (size_t y = 0; y < map_.getRows(); y++) {
    for (size_t x = 0; x < map_.getCols(); x++) {
        DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
    }
  }
}
