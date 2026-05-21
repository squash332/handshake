#pragma once

#include "common.hpp"
#include "map.hpp"
#include "raylib.h"

class MapRenderer
{
public:
  explicit MapRenderer(const Map& map);
  ~MapRenderer();
  void draw();

  inline Rectangle getTileRect(TileType type)
  {
    switch (type) {
      // row 0
      case TileType::Desk:
        return {0 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::Phone:
        return {1 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::Pencil:
        return {2 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::Unknown:
        return {3 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::CupOfPens:
        return {4 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::Paper:
        return {5 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::Parquet:
        return {6 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::LightCarpet:
        return {7 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
      case TileType::DoorTop:
        return {8 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};

      // row 1
      case TileType::Phone2:
        return {0 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::Keyboard:
        return {1 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::Mouse:
        return {2 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::Monitor:
        return {3 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::Extinguisher:
        return {4 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::Board:
        return {5 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::BathroomTile:
        return {6 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::DarkCarpet:
        return {7 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};
      case TileType::DoorBottom:
        return {8 * TILE_SIZE, TILE_SIZE, TILE_SIZE, TILE_SIZE};

      default:
        return {0, 0, TILE_SIZE, TILE_SIZE};
    }
  }

private:
  const Map& map_;
  Texture2D tileset_;
};
