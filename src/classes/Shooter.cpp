#include"Shooter.hpp"
// how to implement active inactive locked state behaviours
Shooter::Shooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:cooldownPeriod(inCooldownPeriod),position(inPosition),attachedMissile(inMissile)
{
    cooldownEnabled = true;
    onStart = false;
    state = State::LOCKED;
}
std::vector<Missile*>* Shooter::shoot()
{
    checkState();
    if(onStart && state == State::ACTIVE)
    {
        onStart = false;
    }
    if(state == State::ACTIVE)
    {
        resetTimer();
    }
    return nullptr;
}
void Shooter::resetTimer()
{
    fireInterval.restart();
}
void Shooter::draw(sf::RenderWindow &window)
{
    checkState();
}
void Shooter::toggleCooldown(bool active)
{
    cooldownEnabled = active;
}
void Shooter::setCooldownPeriod(sf::Time t)
{
    cooldownPeriod = t;
}
void Shooter::unlock()
{
    if(state == State::LOCKED)
    {
        state = State::ACTIVE;
        onStart = true;
    }
}
void Shooter::checkState()
{
    if(state == State::LOCKED){}
    else if(onStart)
    {
        state = State::ACTIVE;
    }
    else if(cooldownEnabled && fireInterval.getElapsedTime() < cooldownPeriod)
    {
        state = State::INACTIVE;
    }
    else
    {
        state = State::ACTIVE;
    }
}



NormalShooter::NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    graphicTexture.loadFromFile(settings::normalShooterImage);
    graphics.setTexture(graphicTexture);
    type = settings::shooterType::normalShooter;
}
std::vector<Missile*>* NormalShooter::shoot() //override
{
    Shooter::shoot();
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    return shootingMissiles;
}
void NormalShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    if(state == State::ACTIVE)
    {

    }
    else if (state == State::INACTIVE)
    {

    }
    else
    {

    }
    graphics.setPosition(window.getView().getSize().x * 0.0f, window.getView().getSize().y * 0.9f);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    window.draw(graphics);
}
void NormalShooter::makeAbstract(){}





SpreadShooter::SpreadShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    type = settings::shooterType::spreadShooter;
    graphicTexture.loadFromFile(settings::spreadShooterImage);
    graphics.setTexture(graphicTexture);

}
std::vector<Missile*>* SpreadShooter::shoot() //override
{
    Shooter::shoot();
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    return shootingMissiles;
}
void SpreadShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    if(state == State::ACTIVE)
    {

    }
    else if (state == State::INACTIVE)
    {

    }
    else
    {

    }
    graphics.setPosition(window.getView().getSize().x * 0.44f, window.getView().getSize().y * 0.9f);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    window.draw(graphics);
}
void SpreadShooter::makeAbstract(){}





RapidShooter::RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    type = settings::shooterType::rapidShooter;
    graphicTexture.loadFromFile(settings::rapidShooterImage);
    graphics.setTexture(graphicTexture);
}

std::vector<Missile*>* RapidShooter::shoot() //override
{
    Shooter::shoot();
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    return shootingMissiles;
}
void RapidShooter::draw(sf::RenderWindow &window)
{
    Shooter::draw(window);
    if(state == State::ACTIVE)
    {

    }
    else if (state == State::INACTIVE)
    {

    }
    else
    {

    }
    graphics.setPosition(window.getView().getSize().x * 0.875f, window.getView().getSize().y * 0.9f);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    window.draw(graphics);
}
void RapidShooter::makeAbstract(){}



// sf::ConvexShape* Shooter::getShooterShape()
// {
//     sf::ConvexShape* semicircle = new sf::ConvexShape();
//     semicircle->setPointCount(100); // number of points to define the semicircle

//     float radius = 50.0f; // radius of the semicircle
//     float angle =  M_PI; // 180 degrees in radians

//     for (int i = 0; i < semicircle->getPointCount(); i++) {
//         float a = -(angle * i / semicircle->getPointCount());
//         sf::Vector2f point(radius * std::cos(a), radius * std::sin(a));
//         semicircle->setPoint(i, point);
//     }

//     semicircle->setPosition(0, -100); // set the position
//     return semicircle;
// }