#pragma once
#include <vector>

#include "constants.hpp"

enum class TileType
{  // needed to draw 2 things on 1 tile
  Table,
  Paper,
  Pencil,
  Rubber,
  CupOfPens,
  ScrambledPaper,
  BrickWall,
  Window,
  TopWallGray,
  CoffeeMug,
  Keyboard,
  Mouse,
  Monitor,
  Extinguisher,
  Board,
  FloorTile,
  BrownWallTile,
  GrayDoor,
  Table_1,
  Table_2,
  Table_3,
  ChairLeft,
  ChairDown,
  ChairUp,
  ChairRight, 
  None
};

enum class Buttons
{
  PLAY,
  EXIT
};

struct Tile
{
  TileType floor = TileType::FloorTile;
  TileType object = TileType::None;
  bool walkable = true;
  bool interactable = false;
};

class Map
{
public:
  Map();
  ~Map() = default;

  static Map loadFromFile(const char* path);

  bool isWalkable(int x, int y);
  int getRows() const;
  int getCols() const;
  Tile getTile(int x, int y) const;

private:
  std::vector<std::vector<Tile>> map_;
  int cols_;
  int rows_;
};
