#pragma once

#include<Asteroid.h>

class AsteroidManager
{
private:
    sf::RenderWindow* window;

    int score;
    //Astorid 
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Asteroid*> asteroids; 

    //private functions
    void initAstroid();

    //collision logic
    std::set<std::pair<Asteroid*, Missile*>> activeCollisions;
    std::pair<Asteroid *, Missile *> collision;

public:
    AsteroidManager();
    virtual ~AsteroidManager();

    //Functions
<<<<<<< Updated upstream
=======
    int getScore();
    bool pixelPerfectCollision(const sf::Sprite&, const settings::Circle&, const std::vector<std::vector<bool>>&);
>>>>>>> Stashed changes
    void setWindow(sf::RenderWindow*);
    void updateAsteroids();
    void update();
    void render();
};