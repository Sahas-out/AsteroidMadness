#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include "Missile.hpp"
using namespace std;




class MissileManager {
    vector<Missile*> missiles;

public:
    ~MissileManager() {
        for (Missile* m : missiles) {
            delete m;
        }
        missiles.clear();
    }
    // add missile should be  calling the constructor and 
    void addMissile(Missile* newMissile) {
        missiles.push_back(newMissile);
    }

    void move(RenderWindow& window) {
        for (Missile* missile : missiles) {
            missile->move();
            // window.draw(missile->getShape());
        }

        for (int i = 0; i < missiles.size(); i++) {
            if (missiles[i]->targetreached()) {
                this->handleTargetReached(window, missiles[i]->gettarget());
                this->removeMissile(i);
                i--; 
            }
        }
    }

    void removeMissile(int i) {
        delete this->missiles[i];
        this->missiles.erase(this->missiles.begin() + i);
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
                this->missiles.push_back(m);
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


class MissileManager {
    vector<Missile*> missiles;

public:

    ~MissileManager() {
        for (Missile* m : missiles) {
            delete m;
        }
        missiles.clear();
    }

    bool addMissile(Missile * m) {
        this->missiles.push_back(m);
        return true;
    }

    void move(RenderWindow& window) {
        for (Missile* i : missiles) {
            i->move();
            window.draw(i->getShape());
        }

        for (int i = 0; i < missiles.size(); i++) {
            if (missiles[i]->targetreached()) {
                this->handleTargetReached(window, missiles[i]->gettarget());
                this->removeMissile(i);
                i--; 
            }
        }
    }

    void removeMissile(int i) {
        delete this->missiles[i];
        this->missiles.erase(this->v.begin() + i);
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

    void Map(RenderWindow& window) {
        
    }

    void drawMissiles(RenderWindow& window) {

        while (window.isOpen()) {
            window.clear(); // Clear the window

            this->Map(window, Vector2f(500, 900)); // missiles silo at (500, 900)
            this->move(window);
            window.display(); // Display the frame
        }
    }
};


// addMissiles(list(Missile*))  addds all the missile passed in the list 
// void executeMissileBehaviour calls move if missile.getState() == alive calls explode if missile.getState() == explode
    // removes missile if the state == dead
//  getAllBounds(vector<Circle> Bounds) // adds the bounds of missile if it is in explode state by using missile.getBounds()
// draw(Missile) // iterates and calls the draw fnc