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
std::vector<Missile*> Shooter::shoot(sf::Vector2f targetPosition)
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
    return std::vector<Missile*>();
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
Missile* Shooter::addMissile(sf::Vector2f shooterSize,sf::Vector2f targetPosition)
{
    sf::Vector2f startPosition = 
    sf::Vector2f(
        position.x + shooterSize.x /2 ,
        position.y + shooterSize.y/2
    );
    
    if(attachedMissile == settings::missileType::normalMissile)
    {
        return new NormalMissile(startPosition,targetPosition);
    }
    else if (attachedMissile == settings::missileType::bigMissile)
    {
        return new BigMissile(startPosition,targetPosition);
    }
    else if (attachedMissile == settings::missileType::nukeMissile)
    {
        return new NukeMissile(startPosition,targetPosition);
    }
    else
    {
        return new LineMissile(startPosition,targetPosition);
    }
}


NormalShooter::NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{   
    graphicTexture.loadFromFile(settings::normalShooterImage);
    graphics.setTexture(graphicTexture);
    type = settings::shooterType::normalShooter;
    graphics.setPosition(inPosition);
    
    float width = 100; 
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);

    fadedGraphics = graphics;
    sf::Color color = fadedGraphics.getColor();
    color.a = 64;
    fadedGraphics.setColor(color);
    
    setInvalidSign();
    setLock();

}

void NormalShooter::setInvalidSign()
{
    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.4f; // Adjust scaling as needed
    float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
    invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
    invalidSign.setPosition(
        bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
    );

}
void NormalShooter::setLock()
{

    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);
    lock.setPosition(
        bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
    );
}
std::vector<Missile*> NormalShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return std::vector<Missile*>();}
    std::vector<Missile*> shootingMissiles;
    shootingMissiles.push_back(addMissile(graphics.getGlobalBounds().getSize(), targetPosition));
    return shootingMissiles;
}
void NormalShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    if(state == State::INACTIVE)
    {
        window.draw(fadedGraphics);
        window.draw(invalidSign);
    }
    else if (state == State::LOCKED)
    {
    window.draw(fadedGraphics);
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

    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);

    fadedGraphics = graphics;
    sf::Color color = fadedGraphics.getColor();
    color.a = 64;
    fadedGraphics.setColor(color);

    setLock();
    setInvalidSign();
    missileCount = 5;
    spread = 50;

}
std::vector<Missile*> SpreadShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return std::vector<Missile*>();}
    std::vector<Missile*> shootingMissiles;
    shootingMissiles.push_back(addMissile(graphics.getGlobalBounds().getSize(),targetPosition));
    for(int i =1; i<(missileCount+1)/2; i++)
    {   
        if(targetPosition.x + spread > settings::windowWidth || targetPosition.x - spread < 0)
        {
            break;
        }
        shootingMissiles.push_back(addMissile(graphics.getGlobalBounds().getSize(), sf::Vector2f(targetPosition.x + (i*spread),targetPosition.y)));
        shootingMissiles.push_back(addMissile(graphics.getGlobalBounds().getSize(),sf::Vector2f(targetPosition.x - (i*spread),targetPosition.y)));
    }
    return shootingMissiles;
}
void SpreadShooter::draw(sf::RenderWindow & window)
{
    Shooter::draw(window);
    
    // Set the scale to maintain the original aspect ratio
    if(state == State::INACTIVE)
    {
        window.draw(fadedGraphics);
        window.draw(invalidSign);
    }
    else if (state == State::LOCKED)
    {
    window.draw(fadedGraphics);
    window.draw(lock);
    }
    else
    {
    window.draw(graphics);
    }
}

void SpreadShooter::setInvalidSign()
{
    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.4f; // Adjust scaling as needed
    float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
    invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
    invalidSign.setPosition(
        bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
    );

}
void SpreadShooter::setLock()
{

    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);
    lock.setPosition(
        bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
    );
}
void SpreadShooter::makeAbstract(){}





RapidShooter::RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,int inCooldownPeriod)
:Shooter(inPosition,inMissile,inCooldownPeriod)
{
    type = settings::shooterType::rapidShooter;
    graphicTexture.loadFromFile(settings::rapidShooterImage);
    graphics.setTexture(graphicTexture);
    graphics.setPosition(inPosition);
    
    float width = 100; // desired width
    float height = width / (graphicTexture.getSize().x / (float)graphicTexture.getSize().y);
    graphics.setScale(width / graphicTexture.getSize().x, height / graphicTexture.getSize().y);

    fadedGraphics = graphics;
    sf::Color color = fadedGraphics.getColor();
    color.a = 64;
    fadedGraphics.setColor(color);

    setLock();
    setInvalidSign();
    missileCount = 3;

}
void RapidShooter::setInvalidSign()
{
    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.4f; // Adjust scaling as needed
    float h = w / (invalidSignTexture.getSize().x / (float)invalidSignTexture.getSize().y);
    invalidSign.setScale(w / invalidSignTexture.getSize().x, h / invalidSignTexture.getSize().y);
    invalidSign.setPosition(
        bounds.left + bounds.width / 2 - invalidSign.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - invalidSign.getGlobalBounds().height / 2 + 10
    );

}
void RapidShooter::setLock()
{

    sf::FloatRect bounds = graphics.getGlobalBounds();
    float w = bounds.width * 0.2f; // Adjust scaling as needed
    float h = w / (lockTexture.getSize().x / (float)lockTexture.getSize().y);
    lock.setScale(w / lockTexture.getSize().x, h / lockTexture.getSize().y);
    lock.setPosition(
        bounds.left + bounds.width / 2 - lock.getGlobalBounds().width / 2,
        bounds.top + bounds.height / 2 - lock.getGlobalBounds().height / 2 + 10
    );
}
std::vector<Missile*> RapidShooter::shoot(sf::Vector2f targetPosition) //override
{
    Shooter::shoot(targetPosition);
    if(state != State::ACTIVE){return std::vector<Missile*>();}
    std::vector<Missile*> shootingMissiles ;
    for(int i=0; i<missileCount;i++)
    {
        shootingMissiles.push_back(addMissile(graphics.getGlobalBounds().getSize(),targetPosition));
    }
    return shootingMissiles;
}
void RapidShooter::draw(sf::RenderWindow &window)
{
    Shooter::draw(window);
    // Set the scale to maintain the original aspect ratio
    if(state == State::INACTIVE)
    {
        window.draw(fadedGraphics);
        window.draw(invalidSign);
    }
    else if (state == State::LOCKED)
    {

        window.draw(fadedGraphics);
        window.draw(lock);
    }
    else
    {
        window.draw(graphics);
    }
}
void RapidShooter::makeAbstract(){}


