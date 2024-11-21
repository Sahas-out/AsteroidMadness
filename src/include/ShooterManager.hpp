#include"Shooter.hpp"
#include<vector>
class ShooterManager{
    private : 
    std::vector<Shooter*>shooterList;
    int currentShooter;
    int unlockCounter;
    
    public:
    ShooterManager();
    void drawShooter(sf::RenderWindow & window);
    std::vector<Missile*>* shoot(sf::Vector2f target);
    void selectShooter(int index);
    void unlockNext();

};