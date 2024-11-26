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
    this->destructionSound.setVolume(50.0f); // Set volume (0.0f to 100.0f)
}

AsteroidManager::AsteroidManager()
{  // std::cout<<"hehehhee"<<std::endl;
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

// Functions
bool AsteroidManager::pixelPerfectCollision(const sf::Sprite& sprite, const settings::Circle& circle, const std::vector<std::vector<bool>>& mask) {
    // Get sprite's global transformation
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::Transform transform = sprite.getTransform();

    // Iterate over the circle's pixels
    for (float angle = 0; angle < 360.f; angle += 1.f) {
        sf::Vector2f point = circle.pos + sf::Vector2f(circle.r * cos(angle), circle.r * sin(angle));
        if (bounds.contains(point)) {
            // Convert global point to local sprite coordinates
            sf::Vector2f localPoint = transform.getInverse().transformPoint(point);
            int x = static_cast<int>(localPoint.x);
            int y = static_cast<int>(localPoint.y);

            // Check if the point is within the mask
            if (x >= 0 && y >= 0 && x < mask[0].size() && y < mask.size() && mask[y][x]) {
                return true; // Collision detected
            }
        }
    }
    return false; // No collision
}


void AsteroidManager::updateAsteroids(MissileManager* missileManager)
{
    //generating a random asteroid at spawm time
    this->spawnTimer += 0.2f;
    int collisonHappened = false;
    // if(asteroids.size()<4){
    //     this->asteroids.push_back(new Asteroid(this->window->getSize().x/2,this->window->getSize().y/2,2));
    //     this->asteroids.push_back(new Asteroid(this->window->getSize().x/2+20.0f,this->window->getSize().y/2,1));
    // }
    if(this->spawnTimer >=spawnTimerMax){
        this->asteroids.push_back(new Asteroid(rand() % (this->window->getSize().x - 100),-100.f, rand() % 3));
        this->spawnTimer =0.0f;
    }
    for(int index = 0;index < this->asteroids.size(); index++){
        asteroids[index]->update();

        //remove asteriods at the bottom of the screen
        for(settings::Circle circle : missileManager->getAllBounds())
        {

            if(pixelPerfectCollision(asteroids[index]->getSprite(),circle,asteroids[index]->getMask()))
            {
                collisonHappened = true;
                destructionSound.play();
                this->asteroids.erase(this->asteroids.begin() +index);
                index--;
                break;
            }
        }
        if (collisonHappened){
            collisonHappened =false;
            continue;
        }
        if(this->asteroids[index]->getBounds().top > this->window->getSize().y- 100.0f)
        {
            this->asteroids.erase(this->asteroids.begin() +index);
            index--;
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
