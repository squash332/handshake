#include "player.hpp"

Player::Player(const char* name)
    : Entity(0.0f, 0.0f)
{
  std::cout << "player constructor ran" << std::endl;
}

void Player::update() {}
