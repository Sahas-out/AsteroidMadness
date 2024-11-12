#include"Shooter.hpp"


Shooter::Shooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:cooldownPeriod(inCooldownPeriod),position(inPosition),attachedMissile(inMissile)
{
    cooldownEnabled = false;
    onStart = true;
}
std::vector<Missile*>* Shooter::shoot(){return nullptr;}
bool Shooter::canShoot()
{
    return onStart || (!cooldownEnabled) || fireInterval.getElapsedTime() >= cooldownPeriod ;
}
void Shooter::resetTimer()
{
    if(onStart == true){onStart ==false;}
    fireInterval.restart();
}
sf::ConvexShape* Shooter::getShooterShape()
{
    sf::ConvexShape* semicircle = new sf::ConvexShape();
    semicircle->setPointCount(100); // number of points to define the semicircle

    float radius = 50.0f; // radius of the semicircle
    float angle =  M_PI; // 180 degrees in radians

    for (int i = 0; i < semicircle->getPointCount(); i++) {
        float a = -(angle * i / semicircle->getPointCount());
        sf::Vector2f point(radius * std::cos(a), radius * std::sin(a));
        semicircle->setPoint(i, point);
    }

    semicircle->setPosition(100, 100); // set the position
    return semicircle;
}
void Shooter::draw(sf::RenderWindow &window){}
void Shooter::toggleCooldown(bool active)
{
    cooldownEnabled = active;
}
void Shooter::setCooldownPeriod(sf::Time t)
{
    cooldownPeriod = t;
}

NormalShooter::NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    // graphic = this->getShooterShape();
    // graphicTexture.loadFromFile(settings::normalShooterTexture);
    // graphic->setTexture(&graphicTexture);
}
std::vector<Missile*>* NormalShooter::shoot() //override
{
    if(!canShoot()){return nullptr;}
    resetTimer();
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    return shootingMissiles;
}
void NormalShooter::draw(sf::RenderWindow & window)
{
    // window.draw(*graphic);
    sf::Texture texture ;
    texture.loadFromFile(settings::normalShooterImage);
    sf::Sprite sprite;
    sprite.setPosition(100,200);
    sprite.setTexture(texture);
    
    // Set the scale to maintain the original aspect ratio
    float width = 400; // desired width
    float height = width / (texture.getSize().x / (float)texture.getSize().y);
    sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
    window.draw(sprite);
}
void NormalShooter::makeAbstract(){}