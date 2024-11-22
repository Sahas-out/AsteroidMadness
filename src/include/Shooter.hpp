#include<SFML/System.hpp>
#include"Missile.hpp"
#include<SFML/Graphics.hpp>
#include<cmath>
#include<vector>
class Shooter
{
    private:
        sf::Clock  fireInterval;
        int cooldownPeriod;
        bool    cooldownEnabled;
        settings::missileType  attachedMissile;
        bool    onStart;
    protected:
        enum class State
        {
            LOCKED,
            ACTIVE,
            INACTIVE
        };
        sf::Vector2f position;
        State state;
        sf::Sprite lock;
        sf::Texture lockTexture;
        sf::Sprite invalidSign;
        sf::Texture invalidSignTexture;
    public:
        Shooter(sf::Vector2f inPosition,settings::missileType inMissile ,int  inCooldownPeriod = settings::defaultCooldown);
        void toggleCooldown(bool active);
        void setCooldownPeriod(int  t);
        void checkState();
        void resetTimer();
        virtual std::vector<Missile*>* shoot(sf::Vector2f targetPosition);
        virtual void draw(sf::RenderWindow& window );
        virtual void makeAbstract() = 0;
        void unlock();
        Missile* addMissile(sf::Vector2f targetPosition);
};

class NormalShooter:public Shooter
{
    private:
        //sf::ConvexShape* graphic;
        sf::Sprite graphics;
        sf::Texture graphicTexture;
        settings::shooterType type;
    public:
        NormalShooter(sf::Vector2f inPosition,settings::missileType inMissile,int  inCooldownPeriod = settings::defaultCooldown);
        std::vector<Missile*>* shoot(sf::Vector2f targetPosition) override;
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
        double spread;
    public:
        SpreadShooter(sf::Vector2f inPosition,settings::missileType inMissile,int  inCooldownPeriod = settings::spreadCooldown);
        std::vector<Missile*>* shoot(sf::Vector2f targetPosition) override;
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
        RapidShooter(sf::Vector2f inPosition,settings::missileType inMissile,int  inCooldownPeriod = settings::rapidCooldown);
        std::vector<Missile*> *shoot(sf::Vector2f targetPosition) override;
        void draw(sf::RenderWindow & window) override;
        void makeAbstract() override;
};
