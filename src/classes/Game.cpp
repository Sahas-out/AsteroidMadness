#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(900,1000),"astroid shooter",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
}

void Game::initAsteroidManager()
{
    asteroidManager->setWindow(this->window);
}

Game::Game()
{
    this->initWindow();
    this->initAsteroidManager();
}

Game::~Game()
{
    delete this->window;
}

void Game::run()
{
    while(this->window->isOpen()){
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                this->window->close();
            if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                this->window->close();
        }
        this->asteroidManager->update();
        this->asteroidManager->render();
    }
}


