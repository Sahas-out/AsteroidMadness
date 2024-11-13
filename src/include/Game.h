#pragma once

#include<Asteroid.h>

class Game
{
private:
    sf::RenderWindow* window;

    //Astorid 
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Asteroid*> asteroids; 

    //private functions
    void initwindow(); // for intializing the window
    void initAstroid();

public:
    Game();
    virtual ~Game();

    //Functions
    void run();
    void updateAsteroids();
    void update();
    void render();
};