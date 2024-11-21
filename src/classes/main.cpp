#include"Shooter.hpp"
// #include"Missile.hpp"
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"title");
    NormalShooter n = NormalShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    SpreadShooter s = SpreadShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    RapidShooter r = RapidShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    NormalMissile normalMissile = NormalMissile(sf::Vector2f(100,100),sf::Vector2f(450,450));
    window.setFramerateLimit(60);
    while(window.isOpen())
    {
        sf::Event event ;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){ window.close();}
        }
        window.clear();
        n.draw(window);
        s.draw(window);
        r.draw(window);
        normalMissile.checkState();
        if(Missile::State::ALIVE == normalMissile.getState())
        {
            normalMissile.move();
        }
        if(Missile::State::EXLPODE == normalMissile.getState())
        {
            normalMissile.explode();
        }

        if(Missile::State::DEAD != normalMissile.getState())
        {
            normalMissile.draw(window);
        }
        window.display();
    }
}
