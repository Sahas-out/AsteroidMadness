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
<<<<<<< Updated upstream
    const std::string asteroid_textureFiles [3] = {resource_path + "normal_asteroid.png",resource_path + "quick_asteroid.png",resource_path + "Strong_asteroid.png"}; 
=======
    const std::string spreadShooterImage = resource_path + "silvershooter.png";
    const std::string lockImage = resource_path + "lock.png";
    const std::string invalidSignImage = resource_path + "invalid.png";
    const std::string backgroundImage = resource_path + "backgroundimage.png";
    const std::string cursorImage = resource_path + "crosshair.png";
    const std::string shooter1 = resource_path + "shooter1.png";
    const std::string shooter2 = resource_path + "shooter2.png";
    const std::string shooter3 = resource_path + "shooter3.png";
    const std::string shooter4 = resource_path + "shooter4.png";
    const std::string shooter5 = resource_path + "shooter5.png";
    const std::string shooter6 = resource_path + "shooter6.png";
    const std::string shooter7 = resource_path + "shooter7.png";
    const std::string shooterCursorImage = resource_path + "shooterCursor.png";
    const std::string backgroundMusic = resource_path + "backgroundMusic.mp3";
    const std::string missileSound = resource_path + "missileSound.wav";
    const double shooterWidth = 100;
    const double missileSpeed = 10;

    const double blastRadius = 30;
    const double bigBlastRadius = 100;
    const int explodeDuration = 25;
    const double missileAliveCircleRadius = 3.5;

    const double lineMissileBlastRadius = 65;
    const std::string asteroid_textureFiles [3] = {resource_path + "normal_asteroid.png",resource_path + "quick_asteroid.png",resource_path + "strong_asteroid.png"}; 
    const std::string destructionAudio = resource_path + "destruction.wav";
    const std::string fontFile = resource_path + "arcade.ttf";

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
    // const std::vector<sf::Vector2f>coordinates={
    //     sf::Vector2f(windowWidth * 0.050f, windowHeight * 0.9f),
    //     sf::Vector2f(windowWidth * 0.245f, windowHeight * 0.9f),
    //     sf::Vector2f(windowWidth * 0.465f, windowHeight * 0.9f),
    //     sf::Vector2f(windowWidth * 0.675f, windowHeight * 0.9f),
    //     sf::Vector2f(windowWidth * 0.875f, windowHeight * 0.9f)
    //     };
>>>>>>> Stashed changes
};