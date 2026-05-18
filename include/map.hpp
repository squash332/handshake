#pragma once

#include <vector>
#include "constants.hpp"

enum class TileType
{
    Floor,
    Wall,
    TopWall,
};

struct Tile
{
    TileType type;
    bool walkable;
    bool interactable;
};

class Map
{
public:
    Map() = default;
    ~Map() = default;
    bool isWalkable(int x, int y);
    Tile getTile(int x, int y);
    int getRows();
    int getCols();

private:
    std::vector<std::vector<Tile>> map_;
    int cols_;
    int rows_;
};
