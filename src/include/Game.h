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
    sf::Cursor cursor;
    sf::Image cursorImage;
    sf::Music backgroundMusic;
public:
    void initWindow();
    void initAsteroidManager();
    Game();
    ~Game();
 
    void run();

};

