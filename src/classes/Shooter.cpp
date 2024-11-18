#include"../include/Shooter.hpp"
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

    semicircle->setPosition(0, -100); // set the position
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
    // // window.draw(*graphic);
    // sf::Texture texture ;
    // texture.loadFromFile(settings::normalShooterImage);
    // sf::Sprite sprite;
    // sprite.setPosition(100,200);
    // sprite.setTexture(texture);
    
    // // Set the scale to maintain the original aspect ratio
    // float width = 200; // desired width
    // float height = width / (texture.getSize().x / (float)texture.getSize().y);
    // sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
    // window.draw(sprite);
      imageTexture.loadFromFile(settings::normalShooterImage);
   graphics.setPosition(window.getView().getSize().x * 0.0f, window.getView().getSize().y * 0.9f);
    graphics.setTexture(imageTexture);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (imageTexture.getSize().x / (float)imageTexture.getSize().y);
    graphics.setScale(width / imageTexture.getSize().x, height / imageTexture.getSize().y);
    window.draw(graphics);
}
void NormalShooter::makeAbstract(){}

SpreadShooter::SpreadShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod){}
std::vector<Missile*>* SpreadShooter::shoot() //override
{
    if(!canShoot()){return nullptr;}
    resetTimer();
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    // use missile functions to add multiple missiles on screen
    return shootingMissiles;
}
void SpreadShooter::draw(sf::RenderWindow & window){
  
    imageTexture.loadFromFile(settings::spreadShooterImage);
   graphics.setPosition(window.getView().getSize().x * 0.44f, window.getView().getSize().y * 0.9f);
    graphics.setTexture(imageTexture);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (imageTexture.getSize().x / (float)imageTexture.getSize().y);
    graphics.setScale(width / imageTexture.getSize().x, height / imageTexture.getSize().y);
    window.draw(graphics);
}
void SpreadShooter::makeAbstract(){}
RapidShooter::RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod){}

std::vector<Missile*>* RapidShooter::shoot() //override
{
    if(!canShoot()){return nullptr;}
    resetTimer();
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    // use missile functions to add multiple missiles on screen
    return shootingMissiles;
}
void RapidShooter::draw(sf::RenderWindow &window){
    
    imageTexture.loadFromFile(settings::rapidShooterImage);
   graphics.setPosition(window.getView().getSize().x * 0.875f, window.getView().getSize().y * 0.9f);
    graphics.setTexture(imageTexture);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (imageTexture.getSize().x / (float)imageTexture.getSize().y);
    graphics.setScale(width / imageTexture.getSize().x, height / imageTexture.getSize().y);
    window.draw(graphics);
}
void RapidShooter::makeAbstract(){}