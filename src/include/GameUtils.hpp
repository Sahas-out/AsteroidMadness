#include<SFML/System.hpp>
#include<string>
namespace settings
{
    const sf::Time defaultCooldown(sf::seconds(2));
    enum shooterType {normalShooter=1};
    enum missileType {normalMissile = 1};
    const std::string resource_path = "./resources/";
    const std::string normalShooterTexture = resource_path + "stainless-steel.jpg";
    const std::string normalShooterImage = resource_path + "blueshooter.png";
    const std::string asteroid_textureFiles [3] = {resource_path + "normal_asteroid.png",resource_path + "quick_asteroid.png",resource_path + "Strong_asteroid.png"}; 
};