#include<SFML/System.hpp>
#include"Missile.hpp"
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
    // protected:    
        // sf::Texture imageTexture;
        // sf::Sprite graphics;
        // virtual sf::ConvexShape* getShooterShape();
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
        //sf::ConvexShape* graphic;
        sf::Sprite graphics;
        sf::Texture graphicTexture;
        settings::shooterType type;
    public:
        NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod = settings::defaultCooldown);
        std::vector<Missile*>* shoot() override;
        void draw(sf::RenderWindow & window) override;
        void makeAbstract() override;
};
class SpreadShooter:public Shooter
{
    private:
        settings::shooterType type;
        sf::Sprite graphics;
        sf::Texture graphicTexture;
        int missileCount ;
    public:
        SpreadShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod = settings::spreadCooldown);
        std::vector<Missile*>* shoot() override;
        void draw(sf::RenderWindow & window) override;
        void makeAbstract() override;
};
class RapidShooter:public Shooter
{
    private:
        settings::shooterType type;
        int missileCount;
        sf::Sprite graphics;
        sf::Texture graphicTexture;
    public:
        RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,sf::Time inCooldownPeriod = settings::rapidCooldown);
        std::vector<Missile*> *shoot() override;
        void draw(sf::RenderWindow & window) override;
        void makeAbstract() override;
};
