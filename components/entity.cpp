#include "entity.hpp"

Entity::Entity() {
    health_ = 100;
    std::cout << "entity constructor ran" << std::endl;
}

float Entity::setPosition(int x, int y) {
    x_ = x;
    y_ = y;
}

float Entity::getX() const {
    return x_;
}

float Entity::getY() const {
    return y_;
}