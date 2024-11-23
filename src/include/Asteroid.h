#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Asteroid{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string textureFiles [3] = {"resources/normal_asteroid.png","resources/quick_asteroid.png","resources/Strong_asteroid.png"};
    std::string type; 
    float speed; // current speed of the asteroid
    int hp;  // current hp of the asteroid
    int maxHp;  // maximum hp of the asteroid 
    int pointsAwarded; // points awarded for destroying this astroid;
    float scale = 1.0f;

    void initTexture();
    void initSprite();
    
    void initAttributes(int);
public:
    Asteroid(float pos_x,float pos_y,int type);
    virtual ~Asteroid();

    const sf::FloatRect getBounds() const;
    //functions
    void move(const float dirx, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
};