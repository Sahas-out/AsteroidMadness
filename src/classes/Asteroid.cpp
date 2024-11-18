#include "Asteroid.h"

void Asteroid::initTexture()
{
    //load texture form file    
    if(!this->texture.loadFromFile(this->textureFile))
    {
        std::cout << "Error: couldn't load Astroid texture.";
    }
}

void Asteroid::initSprite()
{
    //set the texture to the sprite
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.1f,0.1f);
}

void Asteroid::initAttributes()
{
    this->type = "normal"; 
    this->speed = 1.0f;
    this->hp = 10;
    this->maxHp = 10;
    this->pointsAwarded = 1;
}

Asteroid::Asteroid(float pos_x,float pos_y)
{
    this->initTexture();
    this->initSprite();
    this->initAttributes();
    this->sprite.setPosition(pos_x,pos_y);
}

Asteroid::~Asteroid()
{
}

const sf::FloatRect Asteroid::getBounds() const
{
    return this->sprite.getGlobalBounds();
}
// rename this move  
void Asteroid::update()
{
    this->sprite.move(0.0f,this->speed);
}

void Asteroid::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
