#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<vector>
namespace settings
{
    const sf::Time defaultCooldown(sf::seconds(2));
    const sf::Time spreadCooldown(sf::seconds(10));
    const sf::Time rapidCooldown (sf::seconds(5));
    enum shooterType {normalShooter=1,spreadShooter=2,rapidShooter=3};
    enum missileType {normalMissile = 1,BigMissile =2};
    const std::string resource_path = "./resources/";
    const std::string rapidShooterImage = resource_path + "purpleshooter.png";
    const std::string normalShooterImage = resource_path + "blueshooter.png";
    const std::string spreadShooterImage = resource_path + "silvershooter.png";
    const double missileSpeed = 1;
    const double blastRadius = 30;
    const double bigBlastRadius = 100;
    const int explodeDuration = 150;
    const double missileAliveCircleRadius = 3.5;

    const double dotProduct(sf::Vector2f a,sf::Vector2f b);
    class Circle
    {
        public:
            float r;
            sf::Vector2f pos;
            Circle(float radius,sf::Vector2f position);
    };
};