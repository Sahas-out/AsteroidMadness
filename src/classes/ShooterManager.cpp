#include"ShooterManager.hpp"
ShooterManager::ShooterManager(sf::RenderWindow * inWindow):window(inWindow){
    unlockCounter = -1;
    ShooterHeight = settings::windowHeight * 0.9f;
    float margin = 50;
    float spaceBetween = (settings::windowWidth - (2*margin)) / settings::totalShootersCount;
    for(int i =0; i<settings::totalShootersCount;i++)
    {
        coordinates.push_back(sf::Vector2f(((i*spaceBetween))+margin,ShooterHeight));
    }
    
    NormalShooter* crap = new NormalShooter(coordinates[3],settings::missileType::normalMissile,settings::shooter1);
    NormalShooter * alright = new NormalShooter(coordinates[2],settings::missileType::bigMissile,settings::shooter2);
    RapidShooter * ohh = new RapidShooter(coordinates[4],settings::missileType::lineMissile,settings::shooter3);
    NormalShooter * woahhh= new NormalShooter(coordinates[1],settings::missileType::nukeMissile,settings::shooter4);
    SpreadShooter * awesome= new SpreadShooter(coordinates[5],settings::missileType::bigMissile,settings::shooter5);
    SpreadShooter * goat = new SpreadShooter(coordinates[0],settings::missileType::lineMissile,settings::shooter6);
    RapidShooter * perfect = new RapidShooter(coordinates[6],settings::nukeMissile,settings::shooter7);
    this->shooterList.insert(shooterList.end(),{crap,alright,ohh,woahhh,awesome,goat,perfect});
    this->unlockNext();
    // this->unlockNext();
    // this->unlockNext();
    // this->unlockNext();
    // this->unlockNext();
    shooterCursorTexture.loadFromFile(settings::shooterCursorImage);
    shooterCursorGraphics.setTexture(shooterCursorTexture);

    float width = 50;
    float height = width / (shooterCursorTexture.getSize().x / (float)shooterCursorTexture.getSize().y);
    shooterCursorGraphics.setScale(width / shooterCursorTexture.getSize().x, height / shooterCursorTexture.getSize().y);
}
    void ShooterManager::render(){
        sf::Vector2f cursorPos =  shooterList[currentShooter]->cursorPosition();
        cursorPos.x -= shooterCursorGraphics.getGlobalBounds().getSize().x/2;
        cursorPos.y -= shooterCursorGraphics.getGlobalBounds().getSize().y;
        shooterCursorGraphics.setPosition(cursorPos);
        window->draw(shooterCursorGraphics);
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
    