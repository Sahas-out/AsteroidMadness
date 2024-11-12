#include<SFML/System.hpp>
#include"Missile.hpp"
#include"GameUtils.hpp"
#include<SFML/Graphics.hpp>
#include<cmath>
#include<vector>
class Shooter
{
    private:
        sf::Vector2f position;
        sf::Clock  fireInterval;
        sf::Time   cooldownPeriod;
        bool    cooldownEnabled;
        settings::missileType  attachedMissile;
        bool    onStart;
    protected:    
        virtual sf::ConvexShape* getShooterShape();
    public:
        Shooter(sf::Vector2f inPosition,settings::missileType inMissile ,sf::Time inCooldownPeriod = settings::defaultCooldown);
        void toggleCooldown(bool active);
        void setCooldownPeriod(sf::Time t);
        bool canShoot();
        void resetTimer();
        virtual std::vector<Missile*>* shoot();
        virtual void draw(sf::RenderWindow& window );
        virtual void makeAbstract() = 0;
};

class NormalShooter:public Shooter
{
    private:
        sf::ConvexShape* graphic;
        sf::Texture graphicTexture;
        settings::shooterType type = settings::shooterType::normalShooter;
    public:
        NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod = settings::defaultCooldown);
        std::vector<Missile*>* shoot() override;
        void draw(sf::RenderWindow & window) override;
        void makeAbstract() override;
};