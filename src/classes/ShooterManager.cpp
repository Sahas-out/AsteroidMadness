#include"ShooterManager.hpp"
ShooterManager::ShooterManager(){
    this->unlockNext();
    NormalShooter* crap = new NormalShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    RapidShooter * alright= new RapidShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    SpreadShooter * awesome= new SpreadShooter(sf::Vector2f(100,300),settings::missileType::normalMissile);
    SpreadShooter * goat= new SpreadShooter(sf::Vector2f(100,300),settings::missileType::bigMissile);
    this->shooterList.insert(shooterList.end(),{crap,alright,awesome,goat});
}
    void ShooterManager::drawShooter(sf::RenderWindow & window){
        for(auto  shooter : shooterList) shooter->draw(window);
    }
    std::vector<Missile*>* ShooterManager::shoot(sf::Vector2f target){
        return shooterList[currentShooter]->shoot(target);
    }
    void ShooterManager::selectShooter(int index){
        this->currentShooter=index;
    }
    void ShooterManager:: unlockNext(){
        shooterList[++unlockCounter]->unlock();
    }
