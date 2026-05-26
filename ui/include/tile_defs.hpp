#pragma once
#include "raylib.h"
#include "map.hpp"
#include "constants.hpp"

inline Rectangle getTileRect(TileType type)
{
    switch (type) {
        // row 0
        case TileType::Table:       return { 0 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Paper:         return { 1 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Pencil:        return { 2 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Rubber:        return { 3 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::CupOfPens:        return { 4 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::ScrambledPaper:return { 5 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::BrickWall:     return {6 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE  };
        case TileType::Window:        return { 7 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE , TILE_SIZE };
        case TileType::TopWallGray:   return { 8 * TILE_SIZE, 0 * TILE_SIZE, TILE_SIZE, TILE_SIZE };

        // row 1
        case TileType::CoffeeMug:     return { 0 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Keyboard:      return { 1 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Mouse:         return { 2 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Monitor:       return { 3 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Extinguisher:  return { 4 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::Board:         return { 5 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::FloorTile:     return { 6 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::BrownWallTile: return { 7 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::GrayDoor:      return { 8 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE };

        // row 2
        case TileType::Table_1:        return { 0 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE , TILE_SIZE };
        case TileType::Table_2:       return { 1 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE , TILE_SIZE };
        case TileType::Table_3:       return { 2 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE,     TILE_SIZE };
        case TileType::ChairLeft:     return { 3 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::ChairDown:     return { 4 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::ChairUp:       return { 5 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE };
        case TileType::ChairRight:    return { 6 * TILE_SIZE, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE };

        

        default: return {0, 0, TILE_SIZE, TILE_SIZE};
    }
}