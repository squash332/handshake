#pragma once

#include "common.hpp"
#include "raylib.h"

enum class TileType {
    Floor,
    Wall, 
    TopWall,
};

struct Tile {
    TileType type;
    bool walkable;
    bool interactable;
};

class Map {
    public:
        void draw();
        bool isWalkable(int x, int y);
        Tile getTile(int x, int y);
    private:
    std::vector<std::vector<Tile>> map_;
};