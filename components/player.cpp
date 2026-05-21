#include "player.hpp"
#include "constants.hpp"
#include "entity.hpp"

Player::Player(const char* name)
    : Entity(0.0f, 0.0f)
{
  std::cout << "player constructor ran" << std::endl;
}

void Player::update() {
    if (next_x_ < 0 || next_y_ < 0 ||next_x_ > VIRTUAL_WIDTH || next_y_ > VIRTUAL_HEIGHT) return;

    next_x_ = x_;
    next_y_ = y_;
    
    
    switch(direction_) {
        case Direction::Up:
            next_y_ -= TILE_SIZE;
            break;
        
        case Direction::Down:
            next_y_ += TILE_SIZE;
            break;
        
        case Direction::Right:
           next_x_ += TILE_SIZE;
            break;
        
        case Direction::Left:
           next_x_ -= TILE_SIZE;
            break;

        default:
            break;
    }
    direction_ = Direction::None; // after moving, set direction to none so he stops moving
}

void Player::setDirection(Direction dir) {
    direction_ = dir;
}

void Player::confirmMove() {
    x_ = next_x_;
    y_ = next_y_;
}

