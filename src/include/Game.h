#pragma once

#include <AsteroidManager.h>
<<<<<<< Updated upstream
=======
#include"MissileManager.hpp"
#include"ShooterManager.hpp"
#include <iostream>
#include <sstream>
>>>>>>> Stashed changes

class Game
{
private:
    sf::RenderWindow* window;
<<<<<<< Updated upstream
    AsteroidManager* asteroidManager = new AsteroidManager();

public:
    void initWindow();
=======
    AsteroidManager* asteroidManager;
    ShooterManager* shooterManager;
    MissileManager* missileManager;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Cursor cursor;
    sf::Image cursorImage;
    sf::Music backgroundMusic;

    //score
    sf::Font font;
    std::ostringstream scoreStream;
    sf::Text scoreText;
    int score;
public:
    void initWindow();
    void initScore();
    void displayScore();
    void initBackground();
>>>>>>> Stashed changes
    void initAsteroidManager();
    Game();
    ~Game();
 
    void run();

};

