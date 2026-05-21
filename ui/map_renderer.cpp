#include "map_renderer.hpp"

#include "constants.hpp"
#include "raylib.h"

#define SPRITE_SIZE 32

// so we have a 2d array [][], need to traverse our window, fill in with the
// tile types write movement for character

MapRenderer::MapRenderer(const Map& map)
    : map_(map)
{
  tileset_ = LoadTexture("sprites/spritesheet.png");
}

MapRenderer::~MapRenderer()
{
  UnloadTexture(tileset_);
}

void MapRenderer::draw() {
    for (size_t y = 0; y < map_.getRows(); y++) {
        for (size_t x = 0; x < map_.getCols(); x++) {
            Tile tile = map_.getTile(x, y);
            Vector2 pos = { (float)x * TILE_SIZE, (float)y * TILE_SIZE };
            DrawTextureRec(tileset_, getTileRect(tile.floor), pos, WHITE);

            // pass 2 - object on top
            if (tile.object != TileType::None)
                DrawTextureRec(tileset_, getTileRect(tile.object), pos, WHITE);
        }
    }
}
