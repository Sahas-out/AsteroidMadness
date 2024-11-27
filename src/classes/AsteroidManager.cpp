#include "AsteroidManager.h"

void AsteroidManager::initAstroid()
{
    this->spawnTimerMax = 50.0f;
}

void AsteroidManager::loadAudioFiles()
{
    if (!this->destructionBuffer.loadFromFile(settings::destructionAudio)) {
    std::cerr << "Error loading destruction sound!" << std::endl;
    }
    sf::Sound destructionSound;
    this->destructionSound.setBuffer(destructionBuffer);
    this->destructionSound.setVolume(20); // Set volume (0.0f to 100.0f)
}

AsteroidManager::AsteroidManager()
{  
    this->score = 0;
    this->loadAudioFiles();
    this->initAstroid();
}

AsteroidManager::~AsteroidManager()
{

    for(auto *asteroid : asteroids){
        delete asteroid;
    }
}

void AsteroidManager::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

int AsteroidManager::getScore()
{
    return this->score;
}

// Functions
bool AsteroidManager::pixelPerfectCollision(const sf::Sprite& sprite, const settings::Circle& circle, const std::vector<std::vector<bool>>& mask) {
    sf::FloatRect circleBounds(circle.pos.x - circle.r, circle.pos.y - circle.r, 2 * circle.r, 2 * circle.r);
    if (!circleBounds.intersects(sprite.getGlobalBounds())) {
        return false; // No collision possible
    }

    sf::Transform transform = sprite.getTransform();
    const int step = 50; // Adjust for performance vs. accuracy

    for (unsigned int y = 0; y < mask.size(); y += step) {
        for (unsigned int x = 0; x < mask[0].size(); x += step) {
            if (mask[y][x]) {
                sf::Vector2f globalPoint = transform.transformPoint(static_cast<float>(x), static_cast<float>(y));
                float dx = globalPoint.x - circle.pos.x;
                float dy = globalPoint.y - circle.pos.y;

                if (dx * dx + dy * dy <= circle.r * circle.r) {
                    return true; // Collision detected
                }
            }
        }
    }
    return false; // No collision
}


void AsteroidManager::updateAsteroids(MissileManager* missileManager)
{
    //generating a random asteroid at spawm time
    this->spawnTimer += 0.1f;
    int collisonHappened = false;
    if(this->spawnTimer >=spawnTimerMax){
        this->asteroids.push_back(new Asteroid(rand() % (this->window->getSize().x - 100),-100.f, rand() % 3));
        this->spawnTimer =0.0f;
    }
    for(int index = 0;index < this->asteroids.size(); index++){
        asteroids[index]->update();
        std::vector<settings::Circle> circles = missileManager->getAllBounds().first;
        std::vector<Missile *> missiles = missileManager->getAllBounds().second;

        
        for (int missile_index = 0;missile_index < missiles.size();missile_index++) {
            if (pixelPerfectCollision(asteroids[index]->getSprite(), circles[missile_index], asteroids[index]->getMask())) {
                collisonHappened = true; 
                collision = std::make_pair(asteroids[index], missiles[missile_index]);
                

                if (activeCollisions.find(collision) == activeCollisions.end()) {
                    asteroids[index]->decreaseHP(); // Process damage only for new collisions
                    activeCollisions.insert(collision); // Mark this collision as active
                    
                    if (asteroids[index]->getHP() <= 0) {
                        this->score += asteroids[index]->getPoints();
                        destructionSound.play();
                        for (auto it = activeCollisions.begin(); it != activeCollisions.end(); ) {
                            if (it->first == asteroids[index]) {
                                it = activeCollisions.erase(it); // Erase and get the next iterator
                            } else {
                                ++it; // Move to the next element
                            }
                        }
                        delete asteroids[index];
                        this->asteroids.erase(this->asteroids.begin() + index);
                        index--;
                        break;
                    }
                }
            }

        }

        if (collisonHappened){
            collisonHappened =false;
            continue;
        }
        if(this->asteroids[index]->getBounds().top > this->window->getSize().y- 50.0f)
        {
            gameOver = true;
        }
    }

}

void AsteroidManager::update(MissileManager* missileManager)
{
    this->updateAsteroids(missileManager);
}

void AsteroidManager::render()
{
    for(auto *asteroid : asteroids){
        asteroid->render(*this->window);
    }
}
