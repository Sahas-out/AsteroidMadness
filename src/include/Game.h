#pragma once

#include <AsteroidManager.h>
#include"MissileManager.hpp"
#include"ShooterManager.hpp"
class Game
{
private:
    sf::RenderWindow* window;
    AsteroidManager* asteroidManager;
    ShooterManager* shooterManager;
    MissileManager* missileManager;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Cursor cursor;
    sf::Image cursorImage;
    sf::Music backgroundMusic;
    bool GameOver;
    sf::Text gameOverText;
public:
    void initWindow();
    void initBackground();
    void initAsteroidManager();
    void handleKeys(sf::Event & event);
    void run();
    Game();
    ~Game();
 

};

