#include <iostream>

#include "raylib.h"
#define CUTE_TILED_IMPLEMENTATION
#include <cstddef>

#include "constants.hpp"
#include "cute_tiled.h"
#include "map.hpp"

Map::Map()
    : rows_(VIRTUAL_HEIGHT / TILE_SIZE)
    , cols_(VIRTUAL_WIDTH / TILE_SIZE)
{
  map_.resize(rows_,
              std::vector<Tile>(
                  cols_, {TileType::FloorTile, TileType::None, true, false}));
}

bool Map::isWalkable(int x, int y)
{
  if (x < 0 || y < 0 || x >= cols_ || y >= rows_) {
    return false;
  }
  return map_[y][x].walkable;
}

Map Map::loadFromFile(const char* path)
{
  Map m;
  cute_tiled_map_t* tiled_map = cute_tiled_load_map_from_file(path, NULL);

  if (!tiled_map) {
    TraceLog(LOG_ERROR, "Failed to load map: %s", path);
    return m;
  }

  cute_tiled_layer_t* layer = tiled_map->layers;
  while (layer) {
    if (layer->data) {
      for (int i = 0; i < layer->data_count; i++) {
        int gid = layer->data[i];
        int x = i % tiled_map->width;
        int y = i / tiled_map->width;
        TraceLog(LOG_INFO, "GID[%d][%d] = %d", x, y, gid);
        switch (gid) {
          case 0:  // empty tile, skip
            break;
          case 1:
            m.map_[y][x] = {TileType::Table, TileType::None, false, false};
            break;
          case 8:
            m.map_[y][x] = {TileType::Window, TileType::None, false, false};
            break;
          case 9:
            m.map_[y][x] = {
                TileType::TopWallGray, TileType::None, false, false};
            break;
          case 13:
            m.map_[y][x] = {TileType::Monitor, TileType::None, false, true};
            break;
          case 14:
            m.map_[y][x] = {
                TileType::Extinguisher, TileType::None, false, true};
            break;
          case 16:
            m.map_[y][x] = {TileType::FloorTile, TileType::None, true, false};
            break;
          case 17:
            m.map_[y][x] = {
                TileType::BrownWallTile, TileType::None, false, true};
            break;
          case 18:
            m.map_[y][x] = {
                TileType::GrayDoor, TileType::None, false, true};
            break;
          case 19:
            m.map_[y][x] = {TileType::Table_1, TileType::None, false, false};
            break;
          case 20:
            m.map_[y][x] = {TileType::Table_2, TileType::None, false, false};
            break;
          case 21:
            m.map_[y][x] = {TileType::Table_3, TileType::None, false, false};
            break;
        }
      }
    }
    layer = layer->next;
  }

  cute_tiled_free_map(tiled_map);
  return m;
}

int Map::getCols() const
{
  return VIRTUAL_WIDTH / TILE_SIZE;
}

int Map::getRows() const
{
  return VIRTUAL_HEIGHT / TILE_SIZE;
}

Tile Map::getTile(int x, int y) const
{
  return map_[y][x];
}
