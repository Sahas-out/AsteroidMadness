#include "Game.h"
#include<iostream>

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(settings::windowWidth,settings::windowHeight),"astroid shooter",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(settings::fps);
}

void Game::initScore()
{
    if (!font.loadFromFile(settings::fontFile)) { // Ensure you have this font in your project directory
        std::cout << "Error: Font file not found" << std::endl;
        return;
    }
    // Create a text object
    scoreText.setFont(font);                // Set the font
    scoreText.setCharacterSize(70);         // Set the text size
    scoreText.setFillColor(sf::Color::White); // Set the text color
    scoreText.setPosition(10.f, 10.f);      // Set the text position
    this->score = asteroidManager->getScore();
}

void Game::displayScore()
{
    score = asteroidManager->getScore();
    scoreStream.str("");          // Clear previous content
    scoreStream.clear();          // Reset flags
    scoreStream << "Score: " << score;
    scoreText.setString(scoreStream.str());
    window->draw(scoreText);
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

    this->initScore();
    cursorImage.loadFromFile(settings::cursorImage);
    cursor.loadFromPixels(cursorImage.getPixelsPtr(),cursorImage.getSize(),sf::Vector2u(cursorImage.getSize().x/2,cursorImage.getSize().y/2));
    window->setMouseCursor(cursor);
    backgroundMusic.openFromFile(settings::backgroundMusic);
    backgroundMusic.setVolume(10);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(100);
    // gameOverText.setFont(sf::Font::);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition
    (settings::windowWidth/2 - gameOverText.getGlobalBounds().getSize().x /2,
    settings::windowHeight/2 - gameOverText.getGlobalBounds().getSize().y/2);
    GameOver = true;
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
            this->handleKeys(event);
        }
        //     if(GameOver)
        //     {
        //         if (event.type == sf::Event::KeyPressed)
        //         {
        //             if(event.key.code == sf::Keyboard::Escape)
        //             {
        //                 this->window->close();
        //             }
        //             if(event.key.code == sf::Keyboard::Space)
        //             {
        //                 //restarts the game
        //                 GameOver = false;
        //                 //clear asteroids and missiles
        //                 continue;
        //             }
        //             if(event.key.code == sf::Keyboard::S)
        //             {
        //                 //save the score
        //             }
        //         }
        //         window->clear();
        //         window->draw(backgroundSprite);
        //         window->draw(gameOverText);
        //         continue;
        //     }
        //     if (event.type == sf::Event::KeyPressed) {
        //         switch (event.key.code) {
        //             case sf::Keyboard::Escape:
        //                 this->window->close();
        //                 break;
        //             case sf::Keyboard::A:
        //                 shooter = shooterManager->getCurrentShooter();
        //                 shooter = (shooter - 1 < 0) ? settings::totalShootersCount - 1 : shooter -1 ;
        //                 shooterManager->selectShooter(shooter);
        //                 break;
        //             case sf::Keyboard::D:
        //                 shooter = shooterManager->getCurrentShooter();
        //                 shooter = (shooter + 1 >= settings::totalShootersCount) ? 0 : shooter +1 ;
        //                 shooterManager->selectShooter(shooter);
        //                 break;
        //             case sf::Keyboard::Num1:
        //                 shooterManager->selectShooter(0); 
        //                 break;
        //             case sf::Keyboard::Num2: 
        //                 shooterManager->selectShooter(1);
        //                 break;
        //             case sf::Keyboard::Num3: 
        //                 shooterManager->selectShooter(2);
        //                 break;
        //             case sf::Keyboard::Num4: 
        //                 shooterManager->selectShooter(3);
        //                 break;
        //             case sf::Keyboard::Num5: 
        //                 shooterManager->selectShooter(4);
        //                 break;
        //             case sf::Keyboard::Num6:
        //                 shooterManager->selectShooter(5);
        //                 break;
        //             case sf::Keyboard::Num7:
        //                 shooterManager->selectShooter(6);
        //                 break;
        //         }
        //     }
        //     if (event.Event::type == sf::Event::MouseButtonPressed){
        //         isMousePressed = true;
        //         mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
        //     }
        // }
        // if(isMousePressed)
        // {
        //     missileManager->addMissile(shooterManager->shoot(mousePosition));
        // }
        
        this->window->clear();
        if(GameOver)
        {
            window->draw(backgroundSprite);
            window->draw(gameOverText);
            window->display();
            continue;
        }
        this->window->draw(backgroundSprite); 
        this->missileManager->update();
        this->asteroidManager->update(missileManager);
        this->shooterManager->render();
        this->asteroidManager->render();
        this->missileManager->render();
        this->displayScore();                             //update and render score
        isMousePressed = false;
        window->display();
    }
}

void Game::handleKeys(sf::Event & event)
{
    int shooter;
    if(GameOver)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            if(event.key.code == sf::Keyboard::Space)
            {
                //restarts the game
                GameOver = false;
                //clear asteroids and missiles
            }
            if(event.key.code == sf::Keyboard::S)
            {
                //save the score
            }
        }
        return;
    }
    if (event.type == sf::Event::KeyPressed) 
    {
        switch (event.key.code) 
        {
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
            case sf::Keyboard::Num6:
                shooterManager->selectShooter(5);
                break;
            case sf::Keyboard::Num7:
                shooterManager->selectShooter(6);
                break;
        }
    }
    if (event.Event::type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
        missileManager->addMissile(shooterManager->shoot(mousePosition));
    }
}


