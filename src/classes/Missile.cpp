#include "Missile.hpp"
Missile::Missile(sf::Vector2f inPosition,sf::Vector2f inTargetPosition)
{
    position = inPosition;
    targetPositon = inTargetPosition;
    
    direction = targetPositon - inPosition;
    double magnitude = sqrt((direction.x*direction.x) + (direction.y*direction.y));
    direction.x/=magnitude;
    direction.y/=magnitude;
    
    speed = settings::missileSpeed;
    blastRadius = settings::blastRadius;
    explodeDuration = settings::explodeDuration;
    state = State::ALIVE;
}
void Missile::move()
{
    if(state != State::ALIVE){return;}
    position.x += direction.x*speed;
    position.y += direction.y*speed;
}
void Missile::checkState()
{
    if(state == State::ALIVE && settings::dotProduct(targetPositon - position,direction) <= 0)
    {
        state = State::EXLPODE;
    }
    else if (state == State::EXLPODE && explodeDuration <= 0)
    {
        state = State::DEAD;
    }
    // else if (this->position.x <  ) handle when missile goes out of window screen
    return;
}
void Missile::draw(sf::RenderWindow &window)
{
    
}
void Missile::explode()
{
    if(state != State::EXLPODE){return;}
    explodeDuration--;
}
Missile::~Missile()
{
    
}
const sf::Vector2f& Missile::getPositon()
{
    return position;
}
const sf::Vector2f& Missile::getTargetPositon()
{
    return targetPositon;
}
Missile::State Missile::getState()
{
    return state;
}
std::vector<settings::Circle> Missile::getBounds()
{
    return std::vector<settings::Circle>();
}
NormalMissile::NormalMissile(sf::Vector2f inPosition,sf::Vector2f inTargetPosition)
:Missile(inPosition,inTargetPosition),
line(sf::Lines,2),
aliveCircle(settings::missileAliveCircleRadius),
explodeCircle(blastRadius)
{
    
    line[0].position = inPosition;
    line[0].color = sf::Color::White;
    line[1].position = getPositon();
    line[1].color = sf::Color::Red;
    aliveCircle.setFillColor(sf::Color::Blue);
    explodeCircle.setFillColor(sf::Color::White);
    explodeCircle.setPosition(getTargetPositon());
}

void NormalMissile::explode()
{
    if(state != State::EXLPODE){return;}
    explodeDuration--;
}

void NormalMissile::draw(sf::RenderWindow &window)
{
    if(state == State::ALIVE)
    {
        line[1].position = getPositon();
        aliveCircle.setPosition(getPositon());
        window.draw(line);
        window.draw(aliveCircle);
    }
    if(state == State::EXLPODE)
    {

        window.draw(explodeCircle);
    }
}
std::vector<settings::Circle> NormalMissile::getBounds()
{
    if(state != State::EXLPODE){return std::vector<settings::Circle>();}
    return std::vector<settings::Circle>
    {
        settings::Circle(explodeCircle.getRadius(),explodeCircle.getPosition())
    };
}
NormalMissile::~NormalMissile()
{
    
}

