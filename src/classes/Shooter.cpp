#include "Shooter.hpp"
// how to implement active inactive locked state behaviours

Shooter::Shooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:cooldownPeriod(inCooldownPeriod),position(inPosition),attachedMissile(inMissile)
{
    cooldownEnabled = true;
    onStart = false;
    state = State::LOCKED;
    lockTexture.loadFromFile(settings::lockImage);
    invalidSignTexture.loadFromFile(settings::invalidSignImage);
    lock.setTexture(lockTexture);
    invalidSign.setTexture(invalidSignTexture);
}
std::vector<Missile*>* Shooter::shoot(sf::Vector2f targetPosition)
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
void Shooter::setCooldownPeriod(int t)
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
    else if(cooldownEnabled && fireInterval.getElapsedTime().asSeconds()*settings::fps < cooldownPeriod)
    {
        state = State::INACTIVE;
    }
    else
    {
        state = State::ACTIVE;
    }
}
Missile* Shooter::addMissile(sf::Vector2f targetPosition)
{
    if(attachedMissile == settings::missileType::normalMissile)
    {
        return new NormalMissile(position,targetPosition);
    }
    else if (attachedMissile == settings::missileType::bigMissile)
    {
        return new BigMissile(position,targetPosition);
    }
    else if (attachedMissile == settings::missileType::nukeMissile)
    {
        return new NukeMissile(position,targetPosition);
    }
    else
    {
        return new LineMissile(position,targetPosition);
    }
}


NormalShooter::NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{   
    graphicTexture.loadFromFile(settings::normalShooterImage);
    graphics.setTexture(graphicTexture);
    type = settings::shooterType::normalShooter;
    graphics.setPosition(inPosition);
}
std::vector<Missile*>* NormalShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    shootingMissiles->push_back(addMissile(targetPosition));
    return shootingMissiles;
}
void NormalShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    //graphics.setPosition(window.getView().getSize().x * 0.0f, window.getView().getSize().y * 0.9f);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    if(state == State::INACTIVE)
    {
        sf::Color color = graphics.getColor();
        color.a = 64;
        graphics.setColor(color);

        sf::FloatRect bounds = graphics.getGlobalBounds();
        invalidSign.setPosition(
            bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
            bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
        );
        float w = bounds.width * 0.2f; // Adjust scaling as needed
        float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
        invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
       // invalidSign.setPosition(window.getView().getSize().x * 0.05f, window.getView().getSize().y * 0.95f);
        window.draw(graphics);
        window.draw(invalidSign);
    }
    // else if (state == State::LOCKED)
    // {
    //     sf::Color color = graphics.getColor();
    //     color.a = 64;
    //     graphics.setColor(color);
    //     lock.setPosition(window.getView().getSize().x * 0.05f, window.getView().getSize().y * 0.95f);
    //     float w = 50;
    //     float h = w / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);

    //     lock.setScale(w / graphicTexture.getSize().x, h / graphicTexture.getSize().y);

    //     window.draw(graphics);
    //     window.draw(lock);
    // }
    else if (state == State::LOCKED)
    {
    sf::Color color = graphics.getColor();
    color.a = 64;
    graphics.setColor(color);

    // Get the bounds of the graphics sprite
    sf::FloatRect bounds = graphics.getGlobalBounds();

    // Position the lock at the center of the graphics sprite
    lock.setPosition(
        bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
    );

    // Scale the lock sprite if needed
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);

    window.draw(graphics);
    window.draw(lock);
    }
    else
    {
    window.draw(graphics);
    }
}
void NormalShooter::makeAbstract(){}





SpreadShooter::SpreadShooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    type = settings::shooterType::spreadShooter;
    graphicTexture.loadFromFile(settings::spreadShooterImage);
    graphics.setTexture(graphicTexture);

    graphics.setPosition(inPosition);

    missileCount = 5;
    spread = 20;

}
std::vector<Missile*>* SpreadShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    for(int i =0; i<(missileCount+1)/2; i++)
    {   
        if(targetPosition.x + spread > settings::windowWidth || targetPosition.x - spread < 0)
        {
            break;
        }
        shootingMissiles->push_back(addMissile(sf::Vector2f(targetPosition.x + spread,targetPosition.y)));
        shootingMissiles->push_back(addMissile(sf::Vector2f(targetPosition.x - spread,targetPosition.y)));
    }
    return shootingMissiles;
}
void SpreadShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    if(state == State::INACTIVE)
    {
        sf::Color color = graphics.getColor();
        color.a = 64;
        graphics.setColor(color);
        sf::FloatRect bounds = graphics.getGlobalBounds();
        invalidSign.setPosition(
        bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
        );
        float w = bounds.width * 0.2f; // Adjust scaling as needed
        float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
        invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
        window.draw(graphics);
        window.draw(invalidSign);
    }
    else if (state == State::LOCKED)
    {
        sf::Color color = graphics.getColor();
        color.a = 64;
        graphics.setColor(color);
        // Get the bounds of the graphics sprite
        sf::FloatRect bounds = graphics.getGlobalBounds();

    // Position the lock at the center of the graphics sprite
        lock.setPosition(
            bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
            bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
        );

    // Scale the lock sprite if needed
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);

    window.draw(graphics);
    window.draw(lock);
    }
    else
    {
    window.draw(graphics);
    }
}
void SpreadShooter::makeAbstract(){}





RapidShooter::RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    type = settings::shooterType::rapidShooter;
    graphicTexture.loadFromFile(settings::rapidShooterImage);
    graphics.setTexture(graphicTexture);

    graphics.setPosition(inPosition);

    missileCount = 3;

}

std::vector<Missile*>* RapidShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return nullptr;}
    std::vector<Missile*>* shootingMissiles = new std::vector<Missile*>();
    // add missiles to it
    for(int i=0; i<missileCount;i++)
    {
        shootingMissiles->push_back(addMissile(targetPosition));
    }
    return shootingMissiles;
}
void RapidShooter::draw(sf::RenderWindow &window)
{
    Shooter::draw(window);

    
    
    // Set the scale to maintain the original aspect ratio
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);
    if(state == State::INACTIVE)
    {
        sf::Color color = graphics.getColor();
        color.a = 64;
        graphics.setColor(color);
        sf::FloatRect bounds = graphics.getGlobalBounds();
        invalidSign.setPosition(
        bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
        );
        float w = bounds.width * 0.2f; // Adjust scaling as needed
        float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
        invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
        window.draw(graphics);
        window.draw(invalidSign);
    }
    else if (state == State::LOCKED)
    {
        sf::Color color = graphics.getColor();
        color.a = 64;
        graphics.setColor(color);
        // Get the bounds of the graphics sprite
        sf::FloatRect bounds = graphics.getGlobalBounds();

    // Position the lock at the center of the graphics sprite
        lock.setPosition(
            bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
            bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
        );

    // Scale the lock sprite if needed
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);

    window.draw(graphics);
    window.draw(lock);
    }
    else
    {
    window.draw(graphics);
    }
}
void RapidShooter::makeAbstract(){}


