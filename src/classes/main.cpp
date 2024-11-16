#include"../include/Shooter.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"title");
    NormalShooter n = NormalShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    SpreadShooter s = SpreadShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    RapidShooter r = RapidShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
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
        window.display();
    }
}
