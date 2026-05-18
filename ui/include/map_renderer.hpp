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

private:
  const Map& map_;
  Texture2D tileset_;
};
