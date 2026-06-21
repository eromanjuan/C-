#include <iostream>
#include <vector>
#include <conio.h> 
#include <windows.h> 
#include <ctime>    // <--- ADD THIS LINE

using namespace std;

// Game Configuration
const int WIDTH = 20;
const int HEIGHT = 17;

// Directions
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Game Variables
int snakeX, snakeY;
int fruitX, fruitY;
int score;

// Struct to represent snake body segments
struct Point {
    int x, y;
};
vector<Point> snakeBody;

bool gameOver;

// Function to initialize game state
void Setup() {
    gameOver = false;
    dir = STOP;
    
    // Center the snake head
    snakeX = WIDTH / 2;
    snakeY = HEIGHT / 2;
    
    // Clear previous body if any, and add initial head position
    snakeBody.clear();
    snakeBody.push_back({snakeX, snakeY});
    
    // Spawn the first fruit
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    
    score = 0;
}

// Function to render the game grid in the console
void Draw() {
    // Move cursor to the top-left to prevent screen flickering
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    // Top wall
    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << endl;

    // Game board body
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Left wall
            if (j == 0) cout << "#";

            // Draw Snake Head
            if (i == snakeY && j == snakeX) {
                cout << "O";
            }
            // Draw Fruit
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            // Draw Snake Body or Empty Space
            else {
                bool printBody = false;
                for (size_t k = 1; k < snakeBody.size(); k++) {
                    if (snakeBody[k].x == j && snakeBody[k].y == i) {
                        cout << "o";
                        printBody = true;
                        break;
                    }
                }
                if (!printBody) cout << " ";
            }

            // Right wall
            if (j == WIDTH - 1) cout << "#";
        }
        cout << endl;
    }

    // Bottom wall
    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << endl;

    // Display Score
    cout << "Score: " << score << endl;
    cout << "Press 'X' to exit game." << endl;
}

// Function to handle asynchronous keyboard inputs
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
            case 'A':
                if (dir != RIGHT) dir = LEFT; // Prevent reversing into self
                break;
            case 'd':
            case 'D':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
            case 'W':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
            case 'S':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
            case 'X':
                gameOver = true;
                break;
        }
    }
}

// Function to handle the game's movement and logic
void Logic() {
    if (dir == STOP) return;

    // Save current head position before moving
    Point prevHead = snakeBody[0];

    // Move Head
    switch (dir) {
        case LEFT:  snakeX--; break;
        case RIGHT: snakeX++; break;
        case UP:    snakeY--; break;
        case DOWN:  snakeY++; break;
        default: break;
    }

    // Wall Collision Check
    if (snakeX < 0 || snakeX >= WIDTH || snakeY < 0 || snakeY >= HEIGHT) {
        gameOver = true;
        return;
    }

    // Self Collision Check
    for (size_t i = 1; i < snakeBody.size(); i++) {
        if (snakeBody[i].x == snakeX && snakeBody[i].y == snakeY) {
            gameOver = true;
            return;
        }
    }

    // Update body segments (shift them forward)
    snakeBody.insert(snakeBody.begin(), {snakeX, snakeY});

    // Fruit Collision Check
    if (snakeX == fruitX && snakeY == fruitY) {
        score += 10;
        // Respawn Fruit at a random location
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } else {
        // If no fruit eaten, remove the tail segment to maintain size
        snakeBody.pop_back();
    }
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    Setup();

    // Main Game Loop
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); // Controls the game speed (100ms delay)
    }

    // Game Over Screen
    system("cls");
    cout << "=========================" << endl;
    cout << "        GAME OVER        " << endl;
    cout << "=========================" << endl;
    cout << "Your Final Score: " << score << endl;
    
    return 0;
}
