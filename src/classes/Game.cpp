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

    // Calculate scale needed to fill window
    float scaleX = static_cast<float>(settings::windowWidth) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(settings::windowHeight) / backgroundTexture.getSize().y;

    // Use the larger scale to ensure full coverage
    float scale = std::max(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    // Center the background if it's larger than the window
    float xPos = (settings::windowWidth - (backgroundTexture.getSize().x * scale)) / 2.0f;
    float yPos = (settings::windowHeight - (backgroundTexture.getSize().y * scale)) / 2.0f;
    
    backgroundSprite.setPosition(xPos, yPos);
}
void Game::run()
{   int index=0;
    shooterManager->selectShooter(index);

    bool isMousePressed = false ;        // check is the mouse is pressed in this frame
    sf::Vector2f mousePosition; // store the values of the mouse position if the mouse is pressed
    while(this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                this->window->close();
            // if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
            //     this->window->close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                    case sf::Keyboard::A:
                        index = (index <= 0) ? 4 : index - 1;
                        shooterManager->selectShooter(index);
                        break;
                    case sf::Keyboard::D:
                        index = (index >= 4) ? 0 : index + 1;
                        shooterManager->selectShooter(index);
                        break;
                    case sf::Keyboard::Num1:
                        index = 0; shooterManager->selectShooter(index); 
                        break;
                    case sf::Keyboard::Num2: 
                        index = 1; shooterManager->selectShooter(index);
                        break;
                    case sf::Keyboard::Num3: 
                        index = 2; shooterManager->selectShooter(index);
                        break;
                    case sf::Keyboard::Num4: 
                        index = 3; shooterManager->selectShooter(index);
                        break;
                    case sf::Keyboard::Num5: 
                        index = 4; shooterManager->selectShooter(index);
                        break;
                }
            }
            if (event.Event::type == sf::Event::MouseButtonPressed){
                isMousePressed = true;
                mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
            }
            // if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::A)
            // {
            //     shooterManager->selectShooter((shooterManager->getCurrentShooter() - 1)%7);
            // }
            // if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::D)
            // {
            //     shooterManager->selectShooter((shooterManager->getCurrentShooter() + 1)%7);
            // }
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



