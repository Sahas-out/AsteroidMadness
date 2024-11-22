#pragma once

#include <AsteroidManager.h>

class Game
{
private:
    sf::RenderWindow* window;
    AsteroidManager* asteroidManager = new AsteroidManager();

public:
    void initWindow();
    void initAsteroidManager();
    Game();
    ~Game();
 
    void run();

};

