// #include"Missile.hpp"
#include<iostream>
#include"Game.h"
int main()
{   
//     sf::RenderWindow window(sf::VideoMode(1920,1080),"title");
//     // sf::Vector2f wrtWindow=window.getView().getSize();
//     // std::vector<sf::Vector2f>coordinates={
//     //     sf::Vector2f(wrtWindow.x * 0.0f, wrtWindow.y * 0.9f),
//     //     sf::Vector2f(wrtWindow.x * 0.22f, wrtWindow.y * 0.9f),
//     //     sf::Vector2f(wrtWindow.x * 0.44f, wrtWindow.y * 0.9f),
//     //     sf::Vector2f(wrtWindow.x * 0.65f, wrtWindow.y * 0.9f),
//     //     sf::Vector2f(wrtWindow.x * 0.875f, wrtWindow.y * 0.9f)
//     //     };
    
//     NormalShooter n = NormalShooter(settings::coordinates[0],settings::missileType::normalMissile);
//     SpreadShooter s = SpreadShooter(settings::coordinates[1],settings::missileType::normalMissile);
//     RapidShooter r = RapidShooter(settings::coordinates[2],settings::missileType::normalMissile);
//     RapidShooter t = RapidShooter(settings::coordinates[3],settings::missileType::normalMissile);
//     RapidShooter u = RapidShooter(settings::coordinates[4],settings::missileType::normalMissile);

//    // NormalMissile normalMissile = NormalMissile(sf::Vector2f(100,100),sf::Vector2f(450,450));

//     // NormalShooter n = NormalShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
//     // SpreadShooter s = SpreadShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
//     // RapidShooter r = RapidShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
//     // NormalMissile normalMissile = NormalMissile(sf::Vector2f(100,100),sf::Vector2f(450,450));
//     // BigMissile normalMissile = BigMissile(sf::Vector2f(450,450),sf::Vector2f(100,100));
//     // NukeMissile normalMissile = NukeMissile(sf::Vector2f(350,350),sf::Vector2f(100,100));
//     LineMissile normalMissile = LineMissile(sf::Vector2f(350,350),sf::Vector2f(100,100));
//     window.setFramerateLimit(60);
//     while(window.isOpen())
//     {
//         sf::Event event ;
//         while(window.pollEvent(event))
//         {
//             if(event.type == sf::Event::Closed){ window.close();}
//         }
//         window.clear();
//         n.draw(window);
//         s.draw(window);
//         r.draw(window);
//         t.draw(window);
//         u.draw(window);

//         normalMissile.checkState();
//         if(Missile::State::ALIVE == normalMissile.getState())
//         {
//             normalMissile.move();
//         }
//         if(Missile::State::EXLPODE == normalMissile.getState())
//         {
//             normalMissile.explode();
//         }

//         // if(Missile::State::DEAD != normalMissile.getState())
//         // {
//         //     normalMissile.draw(window);
//         // }
//         normalMissile.draw(window);
//         window.display();
//     }
        Game* game = new Game();
        game->run();
        return 0;
}
