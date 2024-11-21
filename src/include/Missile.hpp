#include<SFML/Graphics.hpp>
#include<cmath>
#include"GameUtils.hpp"
class Missile
{
    private:
        sf::Vector2f position;
        sf::Vector2f targetPositon;
        sf::Vector2f direction;
    public:
        enum class State
        {
            ALIVE,
            EXLPODE,
            DEAD
        };
        Missile(sf::Vector2f inPosition,sf::Vector2f inTargetPosition);
        void move();
        void checkState();
        virtual void explode();
        virtual void draw(sf::RenderWindow &window);
        const sf::Vector2f& getPositon();
        const sf::Vector2f& getTargetPositon();
        virtual std::vector<settings::Circle> getBounds();
        State getState();
        ~Missile();
    protected: 
        double speed;
        double blastRadius;
        State state;
        int explodeDuration;

}; 

class NormalMissile : public Missile
{
    private:
        sf::VertexArray line;
        sf::CircleShape aliveCircle;
        sf::CircleShape explodeCircle;
    public:
        NormalMissile(sf::Vector2f inPosition,sf::Vector2f inTargetPosition);
        void draw(sf::RenderWindow &window) override;
        void explode() override;
        std::vector<settings::Circle> getBounds() override;
        ~NormalMissile();
};