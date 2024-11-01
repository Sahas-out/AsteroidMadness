#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace sf;

const int WIDTH = 400;
const int HEIGHT = 400;
const int SIZE = 20;  // size of each grid cell
const int W = WIDTH / SIZE;
const int H = HEIGHT / SIZE;

struct SnakeSegment {
    int x, y;
    SnakeSegment(int x, int y) : x(x), y(y) {}
};

std::vector<SnakeSegment> snake;
int foodX, foodY;
int dirX = 1, dirY = 0;
bool gameOver = false;

void resetGame() {
    snake.clear();
    snake.push_back(SnakeSegment(W / 2, H / 2));
    foodX = rand() % W;
    foodY = rand() % H;
    dirX = 1; dirY = 0;
    gameOver = false;
}

void updateSnake() {
    // Move snake by adding new head
    int newX = snake[0].x + dirX;
    int newY = snake[0].y + dirY;

    // Check for collision with walls or self
    if (newX < 0 || newX >= W || newY < 0 || newY >= H) {
        gameOver = true;
        return;
    }
    for (const auto& segment : snake) {
        if (segment.x == newX && segment.y == newY) {
            gameOver = true;
            return;
        }
    }

    snake.insert(snake.begin(), SnakeSegment(newX, newY));

    // Check if food is eaten
    if (newX == foodX && newY == foodY) {
        foodX = rand() % W;
        foodY = rand() % H;
    } else {
        snake.pop_back();
    }
}

int main() {
    srand(time(0));

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game in SFML");
    resetGame();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Controls: Arrow keys
        if (Keyboard::isKeyPressed(Keyboard::Up) && dirY == 0) { dirX = 0; dirY = -1; }
        if (Keyboard::isKeyPressed(Keyboard::Down) && dirY == 0) { dirX = 0; dirY = 1; }
        if (Keyboard::isKeyPressed(Keyboard::Left) && dirX == 0) { dirX = -1; dirY = 0; }
        if (Keyboard::isKeyPressed(Keyboard::Right) && dirX == 0) { dirX = 1; dirY = 0; }

        // Game over reset
        if (gameOver) {
            resetGame();
        } else {
            updateSnake();
        }

        window.clear(Color::Black);

        // Draw food
        RectangleShape food(Vector2f(SIZE, SIZE));
        food.setFillColor(Color::Red);
        food.setPosition(foodX * SIZE, foodY * SIZE);
        window.draw(food);

        // Draw snake
        for (const auto& segment : snake) {
            RectangleShape rectangle(Vector2f(SIZE - 1, SIZE - 1)); // slightly smaller to show grid lines
            rectangle.setFillColor(Color::Green);
            rectangle.setPosition(segment.x * SIZE, segment.y * SIZE);
            window.draw(rectangle);
        }

        window.display();

        // Control game speed
        sleep(milliseconds(100));
    }

    return 0;
}
