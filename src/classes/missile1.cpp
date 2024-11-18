#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

// Base Missile Class
class Missile {
protected:
    sf::Vector2f position;            // Current position
    sf::Vector2f directionOfMovement; // Movement vector
    sf::Vector2f speed;               // Speed vector
    int impactRadius;                 // Blast radius
    bool isAlive;                     // Alive or blasting
    bool specialEffectOnBlast;        // Special effects on blast
    sf::Texture texture;              // Missile texture
    sf::Sprite sprite;                // Missile sprite
    std::string type;                 // Type of missile

public:
    Missile(const std::string& imagePath, sf::Vector2f startPos, sf::Vector2f dir, sf::Vector2f spd, const std::string& missileType)
        : position(startPos), directionOfMovement(dir), speed(spd), impactRadius(50),
          isAlive(true), specialEffectOnBlast(false), type(missileType) {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Failed to load image: " << imagePath << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(0.1f, 0.1f); // Scaling down sprite
    }

    virtual void move() {
        position.x += directionOfMovement.x * speed.x;
        position.y += directionOfMovement.y * speed.y;
        sprite.setPosition(position);
}


    virtual void draw(sf::RenderWindow& window) const {
        if (isAlive) {
            window.draw(sprite);
        }
    }

    virtual void effectOnBlast() {
        specialEffectOnBlast = true;
        std::cout << "Default blast effect triggered!\n";
    }

    int getImpactRadius() const { return impactRadius; }
    std::string getType() const { return type; }
    bool isOutOfBounds(int windowWidth, int windowHeight) const {
        return position.x < 0 || position.x > windowWidth || position.y < 0 || position.y > windowHeight;
    }
};

// Derived Missile Class for Effects
class SpecialMissile : public Missile {
private:
    sf::SoundBuffer blastSoundBuffer;
    sf::Sound blastSound;

public:
    SpecialMissile(const std::string& imagePath, sf::Vector2f startPos, sf::Vector2f dir, sf::Vector2f spd)
        : Missile(imagePath, startPos, dir, spd, "SpecialMissile") {
        if (blastSoundBuffer.loadFromFile("blast.wav")) { // Add  sound file path
            blastSound.setBuffer(blastSoundBuffer);
        }
    }

    void effectOnBlast() override {
        specialEffectOnBlast = true;
        blastSound.play();
        std::cout << "Special missile blast effect triggered!\n";
    }

    void draw(sf::RenderWindow& window) const override {
        if (isAlive) {
            window.draw(sprite); // Render as usual
        } else {
            // Render special blast graphics
        }
    }
};

// Main Function
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Missile Game");
    window.setFramerateLimit(60);

    std::vector<Missile*> missiles; // Storing base and derived objects
    std::string missileImage = "missile.png"; // Replace with your image path

    // Timer for automatic missile spawning
    auto lastSpawnTime = std::chrono::steady_clock::now();
    const int spawnInterval = 2000; // Spawn missiles every 2 seconds

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Spawn standard missile on spacebar press
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                sf::Vector2f startPos(100, 550);    // Start position
                sf::Vector2f dir(0.0f, -1.0f);     // Direction up
                sf::Vector2f spd(0.0f, 5.0f);      // Speed scaled for x and y)

                missiles.push_back(new Missile(missileImage, startPos, dir, spd, "PlayerMissile"));
            }

            // Spawn special missile on 'S' press
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                sf::Vector2f startPos(400, 550);
                sf::Vector2f dir(0.0f, -1.0f);
                sf::Vector2f spd(0.0f, 5.0f);

                missiles.push_back(new SpecialMissile(missileImage, startPos, dir, spd));
            }
        }

        // Automatically spawn missiles
        auto currentTime = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastSpawnTime).count() > spawnInterval) {
            sf::Vector2f startPos(rand() % 800, 550); // Random X position
            sf::Vector2f dir(0.0f, -1.0f);           // Direction
            sf::Vector2f spd(0.0f, 3.0f);            // Speed

            missiles.push_back(new Missile(missileImage, startPos, dir, spd, "EnemyMissile"));
            lastSpawnTime = currentTime;
        }

        // Move and update missiles
        for (auto& missile : missiles) {
            missile->move();
        }

        // Remove out-of-bounds missiles
        missiles.erase(
            std::remove_if(missiles.begin(), missiles.end(),
                [&window](Missile* missile) {
                    if (missile->isOutOfBounds(window.getSize().x, window.getSize().y)) {
                        delete missile; // Clean up memory
                        return true;
                    }
                    return false;
                }),
            missiles.end()
        );

        // Render missiles
        window.clear(sf::Color::Black);
        for (const auto& missile : missiles) {
            missile->draw(window);
        }
        window.display();
    }

    // Clean up dynamically allocated missiles
    for (auto& missile : missiles) {
        delete missile;
    }

    return 0;
}
