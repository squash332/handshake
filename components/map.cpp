#include "map.hpp"

bool Map::isWalkable(int x, int y)
{
  if (x >= cols_ || y >= rows_) {
    return false;
  }

  return map_[y][x].walkable;
}

int Map::getCols()
{
  return VIRTUAL_WIDTH / TILE_SIZE;
}

int Map::getRows() {
  return VIRTUAL_HEIGHT / TILE_SIZE;
}
