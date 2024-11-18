#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

// Supporting Structures
struct Trajectory {
    float dx, dy; // Direction of movement
};

struct Coordinates {
    int x, y; // Position on a 2D plane
};

struct Image {
    sf::Texture texture; // SFML texture for the missile image
    sf::Sprite sprite;   // SFML sprite for rendering
};

// Missile Class
class Missile {
private:
    int speed;
    int size;
    Trajectory trajectory;
    int impactPerimeter;
    bool specialEffectOnBlast;
    Coordinates targetCoordinates;
    Image image;
    std::string type;

public:
    // Constructor
    Missile(const std::string& imagePath, int x, int y, int spd, Trajectory traj, const std::string& missileType)
        : speed(spd), size(10), trajectory(traj), impactPerimeter(50), specialEffectOnBlast(false),
          targetCoordinates({x, y}), type(missileType) {
        if (!image.texture.loadFromFile(imagePath)) {
            std::cerr << "Failed to load image: " << imagePath << std::endl;
        }
        image.sprite.setTexture(image.texture);
        image.sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
        image.sprite.setScale(0.1f, 0.1f); // Scale down the missile
    }

    // Move the missile
    void move() {
        targetCoordinates.x += static_cast<int>(trajectory.dx * speed);
        targetCoordinates.y += static_cast<int>(trajectory.dy * speed);
        image.sprite.setPosition(static_cast<float>(targetCoordinates.x), static_cast<float>(targetCoordinates.y));
    }

    // Get the missile image
    Image getImage() const {
        return image;
    }

    // Get the missile type
    std::string getType() const {
        return type;
    }

    // Set trajectory
    void setTrajectory(const Trajectory& traj) {
        trajectory = traj;
    }

    // Set the impact perimeter
    void setImpactPerimeter(int perimeter) {
        impactPerimeter = perimeter;
    }

    // Effect on blast (virtual method)
    void effectOnBlast() {
        specialEffectOnBlast = true;
        std::cout << "Blast effect triggered!\n";
    }

    // Draw the missile
    void draw(sf::RenderWindow& window) const {
        window.draw(image.sprite);
    }

    // Check if missile is out of bounds
    bool isOutOfBounds(int windowWidth, int windowHeight) const {
        return targetCoordinates.x < 0 || targetCoordinates.x > windowWidth ||
               targetCoordinates.y < 0 || targetCoordinates.y > windowHeight;
    }
};

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroid Game - Unified Missile Code");
    window.setFramerateLimit(60);

    std::vector<Missile> missiles;
    std::string missileImage = "missile.png"; // Replace with the path to your missile image

    // Timer for automatic missile spawning
    auto lastSpawnTime = std::chrono::steady_clock::now();
    const int spawnInterval = 2000; // Spawn missiles every 2 seconds

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Spawn missile on spacebar press
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                Trajectory trajectory = {0.0f, -1.0f}; // Moves upward
                Missile missile(missileImage, 400, 550, 5, trajectory, "PlayerMissile");
                missiles.push_back(missile);
            }
        }

        // Automatically spawn missiles
        auto currentTime = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastSpawnTime).count() > spawnInterval) {
            Trajectory trajectory = {0.0f, -1.0f};
            int randomX = rand() % 800; // Random X position
            Missile missile(missileImage, randomX, 550, 3, trajectory, "EnemyMissile");
            missiles.push_back(missile);
            lastSpawnTime = currentTime;
        }

        // Move missiles
        for (auto& missile : missiles) {
            missile.move();
        }

        // Remove missiles that go out of bounds
        missiles.erase(
            std::remove_if(missiles.begin(), missiles.end(),
                [&window](const Missile& missile) {
                    return missile.isOutOfBounds(window.getSize().x, window.getSize().y);
                }),
            missiles.end()
        );

        // Render
        window.clear(sf::Color::Black);
        for (const auto& missile : missiles) {
            missile.draw(window);
        }
        window.display();
    }

    return 0;
}
