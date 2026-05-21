#include "map.hpp"

#include "constants.hpp"

Map::Map()
    : rows_(VIRTUAL_HEIGHT / TILE_SIZE)
    , cols_(VIRTUAL_WIDTH / TILE_SIZE)
{
    map_.resize(rows_, std::vector<Tile>(cols_, {TileType::Parquet, TileType::None, true, false}));
}

Map Map::createOffice()
{
    Map m;

    for (int y = 0; y < m.rows_; y++)
        for (int x = 0; x < m.cols_; x++)
            m.map_[y][x] = {TileType::Parquet, TileType::None, true, false};

    for (int x = 0; x < m.cols_; x++) {
        m.map_[0][x]           = {TileType::BathroomTile, TileType::None, false, false};
        m.map_[m.rows_-1][x]   = {TileType::BathroomTile, TileType::None, false, false};
    }
    for (int y = 0; y < m.rows_; y++) {
        m.map_[y][0]           = {TileType::BathroomTile, TileType::None, false, false};
        m.map_[y][m.cols_-1]   = {TileType::BathroomTile, TileType::None, false, false};
    }

    m.map_[m.rows_-2][m.cols_/2] = {TileType::Parquet, TileType::DoorTop,    true, true};
    m.map_[m.rows_-1][m.cols_/2] = {TileType::Parquet, TileType::DoorBottom, true, true};

    m.map_[3][5] = {TileType::Parquet, TileType::Desk, false, true};

    return m;
}

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

int Map::getRows() const
{
  return VIRTUAL_HEIGHT / TILE_SIZE;
}

Tile Map::getTile(int x, int y) const
{
  return map_[y][x];
}
