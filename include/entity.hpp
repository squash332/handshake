#pragma once

#include "common.hpp"

class Entity
{
public:
  Entity(float, float);
  virtual ~Entity() = default;

  virtual void update() = 0;

  void setPosition(float, float);
  float getX() const;
  float getY() const;

protected:
  uint16_t health_;
  const char* name_;
  float x_, y_;
};
