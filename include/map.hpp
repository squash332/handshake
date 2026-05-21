#pragma once

#include <vector>

#include "constants.hpp"

enum class TileType
{
  None,  // needed to draw 2 things on 1 tile
  Desk,
  Phone,
  Pencil,
  Unknown,
  CupOfPens,
  Paper,
  Parquet,
  LightCarpet,
  DoorTop,
  Phone2,
  Keyboard,
  Mouse,
  Monitor,
  Extinguisher,
  Board,
  BathroomTile,
  DarkCarpet,
  DoorBottom
};

struct Tile
{
  TileType floor = TileType::Parquet;
  TileType object = TileType::None;
  bool walkable = true;
  bool interactable = false;
};

class Map
{
public:
  Map();
  static Map createOffice();
  ~Map() = default;
  bool isWalkable(int x, int y);
  int getRows() const;
  int getCols() const;
  Tile getTile(int x, int y) const;

private:
  std::vector<std::vector<Tile>> map_;
  int cols_;
  int rows_;
};
