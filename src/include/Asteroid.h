#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Asteroid{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string textureFile = "resources/Asteroid.png";
    std::string type; 
    float speed; // current speed of the asteroid
    int hp;  // current hp of the asteroid
    int maxHp;  // maximum hp of the asteroid 
    int pointsAwarded; // points awarded for destroying this astroid;
    // something to define direction of movement 
    void initTexture();
    void initSprite();
    void initAttributes();
public:
    Asteroid(float pos_x,float pos_y); // use vector2f for positon and random intialize direction and position vector
    virtual ~Asteroid();

    const sf::FloatRect getBounds() const;
    //functions
    void move(const float dirx, const float dirY); // udate the positon 
    void update();
    void render(sf::RenderTarget& target); // rename to draw
    // get points awarded method
    // a get type method

};