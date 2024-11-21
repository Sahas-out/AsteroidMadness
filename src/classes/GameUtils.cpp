#include"GameUtils.hpp"

const double settings::dotProduct(sf::Vector2f a,sf::Vector2f b)
    {
        return ((a.x * b.x) +(a.y * b.y));
    }
settings::Circle::Circle(float radius,sf::Vector2f position)
{
    this->r = radius;
    this->pos = position;
}