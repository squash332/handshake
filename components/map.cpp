#include "map.hpp"
#include "constants.hpp"

bool Map::isWalkable(int x, int y)
{
  if (x >= cols_ || y >= rows_) {
    return false;
  }

  return map_[y][x].walkable;
}

int Map::getCols() const
{
  return VIRTUAL_WIDTH / TILE_SIZE;
}

int Map::getRows() const {
  return VIRTUAL_HEIGHT / TILE_SIZE;
}
