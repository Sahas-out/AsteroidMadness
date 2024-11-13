#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Semicircle Example");

    // Create a semicircle shape
    sf::CircleShape semicircle;
    semicircle.setRadius(100);
    semicircle.setFillColor(sf::Color::Red);
    semicircle.setScale(1, 0.5);
    semicircle.setOrigin(0, semicircle.getRadius());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(semicircle);
        window.display();
    }

    return 0;
}