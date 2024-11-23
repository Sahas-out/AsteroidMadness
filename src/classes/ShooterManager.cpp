#include"ShooterManager.hpp"
ShooterManager::ShooterManager(sf::RenderWindow & inWindow):window(inWindow){

    this->unlockNext();
    NormalShooter* crap = new NormalShooter(settings::coordinates[0],settings::missileType::normalMissile);
    RapidShooter * alright= new RapidShooter(settings::coordinates[1],settings::missileType::normalMissile);
    SpreadShooter * awesome= new SpreadShooter(settings::coordinates[2],settings::missileType::normalMissile);
    SpreadShooter * serviice= new SpreadShooter(settings::coordinates[3],settings::missileType::bigMissile);
    SpreadShooter * goat= new SpreadShooter(settings::coordinates[4],settings::missileType::bigMissile);

    this->shooterList.insert(shooterList.end(),{crap,alright,awesome,serviice,goat});
}
    void ShooterManager::render(sf::RenderWindow & window){
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
    