#include<SFML/System.hpp>
#include<string>
namespace settings
{
    const sf::Time defaultCooldown(sf::seconds(2));
    const sf::Time spreadCooldown(sf::seconds(10));
    const sf::Time rapidCooldown (sf::seconds(5));
    enum shooterType {normalShooter=1,spreadShooter=2,rapidShooter=3};
    enum missileType {normalMissile = 1};
    const std::string resource_path = "./resources/";
    const std::string rapidShooterImage = resource_path + "purpleshooter.png";
    const std::string normalShooterImage = resource_path + "blueshooter.png";
    const std::string spreadShooterImage = resource_path + "silvershooter.png";
};