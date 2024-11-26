#include "Game.h"

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1200,720),"astroid shooter",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
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
    this->initWindow();
<<<<<<< Updated upstream
    this->initAsteroidManager();
=======

    this->asteroidManager = new AsteroidManager();
    this->initAsteroidManager();
    this->missileManager = new MissileManager(this->window);
    this->shooterManager = new ShooterManager(this->window);
    this->initScore();
    cursorImage.loadFromFile(settings::cursorImage);
    cursor.loadFromPixels(cursorImage.getPixelsPtr(),cursorImage.getSize(),sf::Vector2u(cursorImage.getSize().x/2,cursorImage.getSize().y/2));
    window->setMouseCursor(cursor);
    backgroundMusic.openFromFile(settings::backgroundMusic);
    backgroundMusic.setVolume(20);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
        this->asteroidManager->update();
        this->asteroidManager->render();
    }
}
=======
        if(isMousePressed)
        {
            missileManager->addMissile(shooterManager->shoot(mousePosition));
        }
        
        this->window->clear();
        // this->window->draw(backgroundSprite); 
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

>>>>>>> Stashed changes


