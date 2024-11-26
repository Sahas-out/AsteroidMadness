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
    this->initBackground();
    this->initAsteroidManager();
    this->missileManager = new MissileManager(this->window);
    this->shooterManager = new ShooterManager(this->window);
    cursorImage.loadFromFile(settings::cursorImage);
    cursor.loadFromPixels(cursorImage.getPixelsPtr(),cursorImage.getSize(),sf::Vector2u(cursorImage.getSize().x/2,cursorImage.getSize().y/2));
    window->setMouseCursor(cursor);
    backgroundMusic.openFromFile(settings::backgroundMusic);
    backgroundMusic.setVolume(20);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}

Game::~Game()
{
    delete this->window;
}
void Game::initBackground()
{
    if (!backgroundTexture.loadFromFile(settings::backgroundImage))
    {
        std::cout << "Error loading background!" << std::endl;
        return;
    }

    // Enable smooth scaling
    backgroundTexture.setSmooth(true);
    
    backgroundSprite.setTexture(backgroundTexture);

    
    
    backgroundSprite.setPosition(0, 0);
}
void Game::run()

{   
    // int index=0;
    // shooterManager->selectShooter(index);

    int shooter;
    bool isMousePressed = false ;        // check is the mouse is pressed in this frame
    sf::Vector2f mousePosition; // store the values of the mouse position if the mouse is pressed
    while(this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                this->window->close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                    case sf::Keyboard::A:
                        shooter = shooterManager->getCurrentShooter();
                        shooter = (shooter - 1 < 0) ? settings::totalShootersCount - 1 : shooter -1 ;
                        shooterManager->selectShooter(shooter);
                        break;
                    case sf::Keyboard::D:
                        shooter = shooterManager->getCurrentShooter();
                        shooter = (shooter + 1 >= settings::totalShootersCount) ? 0 : shooter +1 ;
                        shooterManager->selectShooter(shooter);
                        break;
                    case sf::Keyboard::Num1:
                        shooterManager->selectShooter(0); 
                        break;
                    case sf::Keyboard::Num2: 
                        shooterManager->selectShooter(1);
                        break;
                    case sf::Keyboard::Num3: 
                        shooterManager->selectShooter(2);
                        break;
                    case sf::Keyboard::Num4: 
                        shooterManager->selectShooter(3);
                        break;
                    case sf::Keyboard::Num5: 
                        shooterManager->selectShooter(4);
                        break;
                }
            }
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
         this->window->draw(backgroundSprite); 
        this->missileManager->update();
        this->asteroidManager->update(missileManager);
        this->missileManager->render();
        this->shooterManager->render();
        this->asteroidManager->render();
        isMousePressed = false;
        window->display();
    }
    }



