#include <iostream>
#include <vector>
#include <conio.h> 
#include <windows.h> 
#include <ctime>    

using namespace std;

const int WIDTH = 22;
const int HEIGHT = 17;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

int snakeX, snakeY;
int fruitX, fruitY;
int score;

struct Point {
    int x, y;
};
vector<Point> snakeBody;

bool gameOver;

// Function to handle colors
void SetColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void Setup() {
    gameOver = false;
    dir = STOP;
    
    snakeX = WIDTH / 2;
    snakeY = HEIGHT / 2;
    
    snakeBody.clear();
    Point head;
    head.x = snakeX;
    head.y = snakeY;
    snakeBody.push_back(head);
    
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    
    score = 0;
}

void Draw() {
    // Reset cursor to eliminate flickering
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    // --- GAME HEADER ---
    SetColor(11); // Cyan
    cout << "=================================\n";
    cout << "     RETRO SNAKE ARCADE v2.0     \n";
    cout << "=================================\n\n";

    // Top border
    SetColor(8); // Dark Grey wall
    for (int i = 0; i < WIDTH + 2; i++) cout << "¦";
    cout << endl;

    // Game Board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Left Wall
            if (j == 0) {
                SetColor(8);
                cout << "¦";
            }

            // Snake Head
            if (i == snakeY && j == snakeX) {
                SetColor(10); // Bright Green
                cout << "¦"; 
            }
            // Fruit
            else if (i == fruitY && j == fruitX) {
                SetColor(12); // Bright Red
                cout << "?"; 
            }
            // Snake Body / Spaces
            else {
                bool printBody = false;
                for (size_t k = 1; k < snakeBody.size(); k++) {
                    if (snakeBody[k].x == j && snakeBody[k].y == i) {
                        SetColor(2); // Regular Green
                        cout << "¦";
                        printBody = true;
                        break;
                    }
                }
                if (!printBody) cout << " ";
            }

            // Right Wall
            if (j == WIDTH - 1) {
                SetColor(8);
                cout << "¦";
            }
        }
        cout << endl;
    }

    // Bottom border
    SetColor(8);
    for (int i = 0; i < WIDTH + 2; i++) cout << "¦";
    cout << endl << endl;

    // --- UI HUD ---
    SetColor(14); // Yellow Score
    cout << " SCORE: " << score << " pts\n\n";
    
    SetColor(7); // White instructions
    cout << " [W,A,S,D] Move   |   [X] Exit Game\n";
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': case 'A': if (dir != RIGHT) dir = LEFT; break;
            case 'd': case 'D': if (dir != LEFT) dir = RIGHT; break;
            case 'w': case 'W': if (dir != DOWN) dir = UP; break;
            case 's': case 'S': if (dir != UP) dir = DOWN; break;
            case 'x': case 'X': gameOver = true; break;
        }
    }
}

void Logic() {
    if (dir == STOP) return;

    switch (dir) {
        case LEFT:  snakeX--; break;
        case RIGHT: snakeX++; break;
        case UP:    snakeY--; break;
        case DOWN:  snakeY++; break;
        default: break;
    }

    if (snakeX < 0 || snakeX >= WIDTH || snakeY < 0 || snakeY >= HEIGHT) {
        gameOver = true;
        return;
    }

    for (size_t i = 1; i < snakeBody.size(); i++) {
        if (snakeBody[i].x == snakeX && snakeBody[i].y == snakeY) {
            gameOver = true;
            return;
        }
    }

    Point newHead;
    newHead.x = snakeX;
    newHead.y = snakeY;
    snakeBody.insert(snakeBody.begin(), newHead);

    if (snakeX == fruitX && snakeY == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } else {
        snakeBody.pop_back();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Setup();

    // Hide console cursor for a cleaner graphics look
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(80); // Slightly faster speed for smoother frame changes
    }

    // Game over screen
    system("cls");
    SetColor(12);
    cout << "=================================\n";
    cout << "           GAME OVER             \n";
    cout << "=================================\n";
    SetColor(14);
    cout << "  Final Score: " << score << " points\n\n";
    SetColor(7);
    
    return 0;
}
