#pragma once

#include "entity.hpp"

class Player : public Entity
{
public:
  Player(const char* name);

  void update() override;

private:
};
