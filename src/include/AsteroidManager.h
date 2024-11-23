#pragma once

#include<Asteroid.h>

class AsteroidManager
{
private:
    sf::RenderWindow* window;

    //Astorid 
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Asteroid*> asteroids; 

    //private functions
    void initAstroid();

public:
    AsteroidManager();
    virtual ~AsteroidManager();

    //Functions
    void setWindow(sf::RenderWindow*);
    void updateAsteroids();
    void update();
    void render();
};