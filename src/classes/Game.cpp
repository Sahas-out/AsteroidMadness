#include "Game.h"

void Game::initwindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200,720),"astroid shooter",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
}

void Game::initAstroid()
{
    this->spawnTimerMax = 50.0f;
}

Game::Game()
{
    this->initwindow();
    this->initAstroid();
}

Game::~Game()
{
    delete this->window;
    for(auto *asteroid : asteroids){
        delete asteroid;
    }
}

//Functions
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
    
}

void Game::updateAsteroids()
{
    this->spawnTimer += 0.5f;
    if(this->spawnTimer >=spawnTimerMax){
        this->asteroids.push_back(new Asteroid(rand() % (this->window->getSize().x - 100),-100.f));
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

void Game::update()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
        if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }

    this->updateAsteroids();
    
}

void Game::render()
{
    this->window->clear();

    // Draw stuff

    for(auto *asteroid : asteroids){
        asteroid->render(*this->window);
    }

    this->window->display();

}
