#pragma once

#include "Asteroid.h"
#include "GameUtils.hpp"
#include "MissileManager.hpp"
#include <SFML/Audio.hpp>

class AsteroidManager
{
private:
    sf::RenderWindow* window;

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

public:
    AsteroidManager();
    virtual ~AsteroidManager();

    //Functions
    bool pixelPerfectCollision(const sf::Sprite&, const settings::Circle&, const std::vector<std::vector<bool>>&);
    void setWindow(sf::RenderWindow*);
    void updateAsteroids(MissileManager*);
    void update(MissileManager*);
    void render();
};