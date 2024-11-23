#include "AsteroidManager.h"

void AsteroidManager::initAstroid()
{
    this->spawnTimerMax = 50.0f;
}

AsteroidManager::AsteroidManager()
{
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

void AsteroidManager::updateAsteroids()
{
    //generating a random asteroid at spawm time
    this->spawnTimer += 0.5f;
    if(this->spawnTimer >=spawnTimerMax){
        this->asteroids.push_back(new Asteroid(rand() % (this->window->getSize().x - 100),-100.f, rand() % 3));
        this->spawnTimer =0.0f;
    }
    for(int index = 0;index < this->asteroids.size(); index++){
        asteroids[index]->update();

        //remove asteriods at the bottom of the screen
        if(this->asteroids[index]->getBounds().top > this->window->getSize().y- 100.0f)
        {
            this->asteroids.erase(this->asteroids.begin() +index);
        }
    }

}

void AsteroidManager::update()
{
    this->updateAsteroids();
}

void AsteroidManager::render()
{


    for(auto *asteroid : asteroids){
        asteroid->render(*this->window);
    }

}
