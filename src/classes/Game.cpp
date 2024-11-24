#include "Game.h"
#include<iostream>
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(settings::windowWidth,settings::windowHeight),"astroid shooter",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(settings::fps);
}

void Game::initAsteroidManager()
{
    asteroidManager->setWindow(this->window);
}

Game::Game()
{
    this->asteroidManager = new AsteroidManager();

    this->initWindow();
    this->initAsteroidManager();
    this->missileManager = new MissileManager(this->window);
    std::cout<<"constructors done"<<std::endl;
    this->shooterManager = new ShooterManager(this->window);
}

Game::~Game()
{
    delete this->window;
}

void Game::run()
{
    shooterManager->selectShooter(0);

    bool isMousePressed = false ;        // check is the mouse is pressed in this frame
    sf::Vector2f mousePosition; // store the values of the mouse position if the mouse is pressed
    while(this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                this->window->close();
            if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                this->window->close();
            if (event.Event::type == sf::Event::MouseButtonPressed){
                isMousePressed = true;
                mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
            }
        }
        if(isMousePressed)
        {
            missileManager->addMissile(shooterManager->shoot(mousePosition));
        }
        this->window->clear();
        this->missileManager->update();
        this->asteroidManager->update(missileManager);
        this->missileManager->render();
        this->shooterManager->render();
        this->asteroidManager->render();
        isMousePressed = false;
        window->display();
    }
    }



