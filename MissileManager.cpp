#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <cmath>
#include <vector>

using namespace sf;
using namespace std;

class Missile {
    CircleShape c;
    Vector2f target;
    Vector2f speed;

public:
    Missile(Vector2f v, CircleShape c) {
        this->c = c;
        this->target = v;
    }

    void setspeed(Vector2f direction, float length) {
        this->speed = (direction / length) * 0.5f;
    }

    Vector2f gettarget() {
        return target;
    }

    bool targetreached() {
        Vector2f currentpos = this->c.getPosition();
        return abs(currentpos.x - target.x) < 1.0f && abs(currentpos.y - target.y) < 1.0f;
    }

    void move() {
        this->c.move(speed);
    }

    CircleShape& getShape() {
        return c;
    }
};


class MissileManager {
    vector<Missile*> v;

public:
    ~MissileManager() {
        for (Missile* m : v) {
            delete m;
        }
        v.clear();
    }
    // add missile should be  calling the constructor and 
    void addMissile(Missile newMissile) {
        // CircleShape circle(3);
        // circle.setPosition(Vector2f(500, 900));
        // circle.setPointCount(3);
        // circle.setFillColor(Color::Red);

        // return circle;
        v.push_back(newMissile);
    }

    void move(RenderWindow& window) {
        for (Missile* i : v) {
            i->move();
            window.draw(i->getShape());
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i]->targetreached()) {
                this->handleTargetReached(window, v[i]->gettarget());
                this->removeMissile(i);
                i--; 
            }
        }
    }

    void removeMissile(int i) {
        delete this->v[i];
        this->v.erase(this->v.begin() + i);
    }

    void handleTargetReached(RenderWindow& window, Vector2f targetpos) {
        CircleShape c2(2);

        for (float d = 2.0f; d < 50.0; d += 5.0f) {
            c2.setRadius(d);
            c2.setPosition(targetpos - Vector2f(d, d));
            c2.setPointCount(100);
            c2.setFillColor(Color::White);

            

            window.draw(c2);
            window.display();
        }
    }

    void Map(RenderWindow& window, Vector2f initialpos) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f targetpos = Vector2f(Mouse::getPosition(window));
                Missile* m = new Missile(targetpos, this->addMissile());
                Vector2f direction = targetpos - initialpos;
                float length = sqrt(direction.x * direction.x + direction.y * direction.y);
                m->setspeed(direction, length);
                this->v.push_back(m);
            }
        }
    }

    void drawMissiles(RenderWindow& window) {

        while (window.isOpen()) {
            window.clear(); // Clear the window

            this->Map(window, Vector2f(500, 900)); // missiles silo at (500, 900)
            this->move(window);
            window.draw(sprite);
            window.display(); // Display the frame
        }
    }
};

int main() {
    RenderWindow window(VideoMode(1935, 1170), "Asteroid Madness");
    window.setFramerateLimit(200);
    

    MissileManager m;
    m.drawMissiles(window);

    return 0;
}
