#pragma once
#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

namespace settings
{
    const int windowWidth = 1920;
    const int windowHeight = 1080;
    const int fps = 144; 
    const int defaultCooldown = 144;
    const int  spreadCooldown = 144;
    const int  rapidCooldown = 144;
    enum shooterType {normalShooter=1,spreadShooter=2,rapidShooter=3};
    enum missileType {normalMissile = 1,bigMissile =2,nukeMissile = 3,lineMissile = 4};
    const std::string resource_path = "./resources/";
    const std::string rapidShooterImage = resource_path + "purpleshooter.png";
    const std::string normalShooterImage = resource_path + "blueshooter.png";
    const std::string spreadShooterImage = resource_path + "silvershooter.png";
    const std::string lockImage = resource_path + "lock.png";
    const std::string invalidSignImage = resource_path + "invalid.png";
    const std::string backgroundImage = resource_path + "backgroundimage.png";

    const double missileSpeed = 10;

    const double blastRadius = 30;
    const double bigBlastRadius = 100;
    const int explodeDuration = 25;
    const double missileAliveCircleRadius = 3.5;

    const double lineMissileBlastRadius = 65;
    const std::string asteroid_textureFiles [3] = {resource_path + "normal_asteroid.png",resource_path + "quick_asteroid.png",resource_path + "strong_asteroid.png"}; 
    const std::string destructionAudio = resource_path + "destruction.wav";


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
    
    //const sf::Vector2f wrtWindow=window.getView().getSize();
    const std::vector<sf::Vector2f>coordinates={
        sf::Vector2f(windowWidth * 0.050f, windowHeight * 0.9f),
        sf::Vector2f(windowWidth * 0.245f, windowHeight * 0.9f),
        sf::Vector2f(windowWidth * 0.465f, windowHeight * 0.9f),
        sf::Vector2f(windowWidth * 0.675f, windowHeight * 0.9f),
        sf::Vector2f(windowWidth * 0.875f, windowHeight * 0.9f)
        };
};