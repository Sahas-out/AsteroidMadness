#pragma once

#include "Asteroid.h"
#include "GameUtils.hpp"
#include "MissileManager.hpp"
#include <SFML/Audio.hpp>

class AsteroidManager
{
private:
    sf::RenderWindow* window;

    int score;
    //Astorid 
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Asteroid*> asteroids; 
    
    //Audio Effects
    sf::SoundBuffer destructionBuffer;
    sf::Sound destructionSound;

    //private functions
    void initAstroid();
    void loadAudioFiles();

    //collision logic
    std::set<std::pair<Asteroid*, Missile*>> activeCollisions;
    std::pair<Asteroid *, Missile *> collision;

public:
    bool gameOver = false;
    AsteroidManager();
    virtual ~AsteroidManager();

    //Functions
    int getScore();
    bool pixelPerfectCollision(const sf::Sprite&, const settings::Circle&, const std::vector<std::vector<bool>>&);
    void setWindow(sf::RenderWindow*);
    void updateAsteroids(MissileManager*);
    void update(MissileManager*);
    void render();
};