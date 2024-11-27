#pragma once
#include <AsteroidManager.h>
#include"MissileManager.hpp"
#include"ShooterManager.hpp"
#include <iostream>
#include <sstream>

extern "C"
{
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

    //score
    sf::Font font;
    std::ostringstream scoreStream;
    sf::Text scoreText;
    int score;
    int sessionHighScore;
    bool gameOver;
    sf::Text gameOverText;
public:
    void initWindow();
    void initScore();
    void clearScreen();
    void displayScore();
    void initBackground();
    void initAsteroidManager();
    void handleKeys(sf::Event & event);
    void run();
    int getSessionHighScore();
    Game();
    ~Game();
 

};
}
