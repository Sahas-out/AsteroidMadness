#include"Coordinate.hpp"
#include<SFML/System.hpp>
#include"Missile.hpp"
class Shooter
{
    private:
        Coordinate positon;
        sf::Clock  fireInterval;
        sf::Time   cooldownPeriod;
        bool    cooldownEnabled;
        Missile attachedMissile;
    public:
        Shooter(Coordinate inPositon,sf::Time inCooldownPeriod,Missile inMissile);
        virtual void makeAbstract() = 0;
};