#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

namespace settings
{
    const int defaultCooldown = 7200;
    const int  spreadCooldown = 7200;
    const int  rapidCooldown = 7200;
    enum shooterType {normalShooter=1,spreadShooter=2,rapidShooter=3};
    enum missileType {normalMissile = 1,bigMissile =2,nukeMissile = 3,lineMissile = 4};
    const std::string resource_path = "./resources/";
    const std::string rapidShooterImage = resource_path + "purpleshooter.png";
    const std::string normalShooterImage = resource_path + "blueshooter.png";
    const std::string spreadShooterImage = resource_path + "silvershooter.png";
    const std::string lockImage = resource_path + "lock.png";
    const std::string invalidSignImage = resource_path + "invalid.png";
    const double missileSpeed = 1;
    const double blastRadius = 30;
    const double bigBlastRadius = 100;
    const int explodeDuration = 150;
    const double missileAliveCircleRadius = 3.5;

    const double dotProduct(sf::Vector2f a,sf::Vector2f b);
    const void  normalise(sf::Vector2f * vector);
    const sf::Vector2f scalarProduct(sf::Vector2f vector,float scalar);
    class Circle
    {
        public:
            float r;
            sf::Vector2f pos;
            Circle(float radius,sf::Vector2f position);
            Circle();
    };
    const int windowWidth = 900;
    const int windowHeight = 1000;
    const int fps = 60;
    std::string textureFiles [3] = {resource_path + "normal_asteroid.png",resource_path + "quick_asteroid.png",resource_path + "Strong_asteroid.png"}; 
};