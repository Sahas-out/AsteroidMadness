#include"ShooterManager.hpp"
ShooterManager::ShooterManager(sf::RenderWindow * inWindow):window(inWindow){
    unlockCounter = -1;
    NormalShooter* crap = new NormalShooter(settings::coordinates[0],settings::missileType::lineMissile);
    NormalShooter * alright= new NormalShooter(settings::coordinates[1],settings::missileType::bigMissile);
    NormalShooter * awesome= new NormalShooter(settings::coordinates[2],settings::missileType::nukeMissile);
    SpreadShooter * serviice= new SpreadShooter(settings::coordinates[3],settings::missileType::nukeMissile);
    SpreadShooter * goat= new SpreadShooter(settings::coordinates[4],settings::missileType::bigMissile);
    this->shooterList.insert(shooterList.end(),{crap,alright,awesome,serviice,goat});
    this->unlockNext();
    this->unlockNext();
    this->unlockNext();
    this->unlockNext();
    this->unlockNext();
}
    void ShooterManager::render(){
        for(auto  shooter : shooterList) shooter->draw(*window);
    }
    std::vector<Missile*> ShooterManager::shoot(sf::Vector2f target){
        return shooterList[currentShooter]->shoot(target);
    }
    void ShooterManager::selectShooter(int index){
        this->currentShooter=index;
    }
    void ShooterManager:: unlockNext(){
        shooterList[++unlockCounter]->unlock();
    }
    