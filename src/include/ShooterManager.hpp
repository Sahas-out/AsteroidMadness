#pragma once

#include"Shooter.hpp"
#include<vector>
class ShooterManager{
    private : 
    std::vector<Shooter*>shooterList;
    int currentShooter;
    int unlockCounter;
    sf::RenderWindow *window;
    
    public:
    ShooterManager(sf::RenderWindow *inWindow);
    void render();
    std::vector<Missile*> shoot(sf::Vector2f target);
    void selectShooter(int index);
    void unlockNext();
    void Update();

};