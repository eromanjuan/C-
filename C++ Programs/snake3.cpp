#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>

#ifdef _WIN32
  #define NOMINMAX
  #include <windows.h>
#else
  #include <unistd.h>
  #include <termios.h>
  #include <fcntl.h>
#endif

// Simple console Snake (grid-based).
// Windows: uses WinAPI for non-blocking input.
// Non-Windows: fallback to non-blocking termios.

namespace {

#ifdef _WIN32

// Non-blocking single key read. Returns 0 if no key available.
int pollKey() {
    // Check if a key is available
    if (!kbhit()) return 0;
    int ch = getch();
    return ch;
}

#else

static struct termios orig_termios;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Non-blocking reads
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

int pollKey() {
    unsigned char ch;
    ssize_t nread = read(STDIN_FILENO, &ch, 1);
    if (nread <= 0) return 0;
    return ch;
}

#endif

struct Pos {
    int x;
    int y;
    bool operator==(const Pos& other) const { return x == other.x && y == other.y; }
};

enum class Dir { Up, Down, Left, Right };

Pos movePos(const Pos& p, Dir d) {
    switch (d) {
        case Dir::Up:    return {p.x, p.y - 1};
        case Dir::Down:  return {p.x, p.y + 1};
        case Dir::Left:  return {p.x - 1, p.y};
        case Dir::Right: return {p.x + 1, p.y};
    }
    return p;
}

bool isOpposite(Dir a, Dir b) {
    return (a == Dir::Up && b == Dir::Down) ||
           (a == Dir::Down && b == Dir::Up) ||
           (a == Dir::Left && b == Dir::Right) ||
           (a == Dir::Right && b == Dir::Left);
}

void clearScreen() {
#ifdef _WIN32
    // Clear using WinAPI console text attributes
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords{0,0};

    if (hOut && GetConsoleScreenBufferInfo(hOut, &csbi)) {
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hOut, ' ', cellCount, homeCoords, &count);
        FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);
        SetConsoleCursorPosition(hOut, homeCoords);
    } else {
        std::cout << "\x1B[2J\x1B[H";
    }
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}

void render(
    int width, int height,
    const std::vector<Pos>& snake,
    const Pos& food,
    int score,
    int best,
    int tickMs,
    bool gameOver
) {
    clearScreen();

    // top border
    std::cout << '+';
    for (int i = 0; i < width; ++i) std::cout << '-';
    std::cout << "+\n";

    // grid
    for (int y = 0; y < height; ++y) {
        std::cout << '|';
        for (int x = 0; x < width; ++x) {
            Pos cur{x, y};

            char ch = ' ';
            if (cur == food) ch = '*';

            // snake body: head distinct
            for (size_t i = 0; i < snake.size(); ++i) {
                if (snake[i] == cur) {
                    ch = (i == 0) ? '@' : 'o';
                    break;
                }
            }

            // subtle wall shading (optional). Here just spaces.
            std::cout << ch;
        }
        std::cout << "|\n";
    }

    std::cout << '+';
    for (int i = 0; i < width; ++i) std::cout << '-';
    std::cout << "+\n";

    std::cout << "Score: " << score << "   Best: " << best
              << "   Speed: " << (1000 / tickMs) << " steps/s\n";

    if (gameOver) {
        std::cout << "\nGAME OVER! Press R to restart or Q to quit.\n";
    } else {
        std::cout << "Controls: Arrow keys (or WASD). Q quit.\n";
    }
}

Pos randomFoodPos(int width, int height, const std::vector<Pos>& snake, std::mt19937& rng) {
    std::uniform_int_distribution<int> dx(0, width - 1);
    std::uniform_int_distribution<int> dy(0, height - 1);

    auto occupied = [&](const Pos& p) {
        return std::any_of(snake.begin(), snake.end(), [&](const Pos& s) { return s == p; });
    };

    for (int tries = 0; tries < 10000; ++tries) {
        Pos p{dx(rng), dy(rng)};
        if (!occupied(p)) return p;
    }

    // Fallback: scan
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            if (!occupied(Pos{x, y})) return Pos{x, y};

    return Pos{0, 0};
}

Dir keyToDir(int key) {
    // For Windows arrow keys, getch() returns 0 or 224 then next getch() for the actual code.
    // We'll handle that outside.
    switch (key) {
        case 'w': case 'W': return Dir::Up;
        case 'a': case 'A': return Dir::Left;
        case 's': case 'S': return Dir::Down;
        case 'd': case 'D': return Dir::Right;
    }
    return Dir::Up; // dummy
}

} // namespace

int main() {
#ifndef _WIN32
    enableRawMode();
#endif

    const int width = 30;
    const int height = 18;

    int best = 0;
    bool running = true;

    // RNG
    std::mt19937 rng(static_cast<unsigned int>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    ));

    while (running) {
        // Initialize
        std::vector<Pos> snake;
        snake.reserve(width * height);

        int startX = width / 2;
        int startY = height / 2;
        snake.push_back({startX, startY});
        snake.push_back({startX - 1, startY});
        snake.push_back({startX - 2, startY});

        Dir dir = Dir::Right;
        Dir pendingDir = dir;

        Pos food = randomFoodPos(width, height, snake, rng);

        int score = 0;
        bool gameOver = false;

        // Timing / speed
        int tickMs = 120; // lower is faster
        int minTickMs = 65;
        int growthPerFood = 1;

        auto lastTick = std::chrono::steady_clock::now();

        render(width, height, snake, food, score, best, tickMs, gameOver);

        while (!gameOver && running) {
            // Input polling
#ifdef _WIN32
            // Windows special handling for arrow keys
            int ch = pollKey();
            if (ch) {
                if (ch == 'q' || ch == 'Q') {
                    running = false;
                    break;
                }
                if (ch == 'r' || ch == 'R') {
                    // ignore during game
                }

                // Arrow keys on Windows: first code 0 or 224
                if (ch == 0 || ch == 224) {
                    int ch2 = pollKey();
                    Dir nd = dir;
                    if (ch2 == 72) nd = Dir::Up;
                    else if (ch2 == 80) nd = Dir::Down;
                    else if (ch2 == 75) nd = Dir::Left;
                    else if (ch2 == 77) nd = Dir::Right;
                    if (!isOpposite(dir, nd)) pendingDir = nd;
                } else {
                    // WASD
                    Dir nd = dir;
                    if (ch == 'w' || ch == 'W') nd = Dir::Up;
                    else if (ch == 's' || ch == 'S') nd = Dir::Down;
                    else if (ch == 'a' || ch == 'A') nd = Dir::Left;
                    else if (ch == 'd' || ch == 'D') nd = Dir::Right;
                    if (!isOpposite(dir, nd)) pendingDir = nd;
                }
            }
#else
            int ch = pollKey();
            if (ch) {
                if (ch == 'q' || ch == 'Q') {
                    running = false;
                    break;
                }
                if (ch == 'w' || ch == 'W') { if (!isOpposite(dir, Dir::Up)) pendingDir = Dir::Up; }
                else if (ch == 's' || ch == 'S') { if (!isOpposite(dir, Dir::Down)) pendingDir = Dir::Down; }
                else if (ch == 'a' || ch == 'A') { if (!isOpposite(dir, Dir::Left)) pendingDir = Dir::Left; }
                else if (ch == 'd' || ch == 'D') { if (!isOpposite(dir, Dir::Right)) pendingDir = Dir::Right; }
                // Arrow keys parsing is terminal-dependent; omitted for portability.
            }
#endif

            // Tick update
            auto now = std::chrono::steady_clock::now();
            int elapsedMs = (int)std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTick).count();
            if (elapsedMs >= tickMs) {
                lastTick = now;

                dir = pendingDir;
                Pos next = movePos(snake[0], dir);

                // Wall collision
                if (next.x < 0 || next.x >= width || next.y < 0 || next.y >= height) {
                    gameOver = true;
                    break;
                }

                // Self collision: allow moving into tail if tail will move away (when not eating).
                bool willGrow = (next == food);
                Pos tail = snake.back();

                for (size_t i = 0; i < snake.size(); ++i) {
                    if (snake[i] == next) {
                        bool collides = true;
                        if (!willGrow && snake.size() > 1 && snake.back() == next) {
                            // tail will move, so it's not a collision
                            collides = false;
                        }
                        if (collides) {
                            gameOver = true;
                            break;
                        }
                    }
                }
                if (gameOver) break;

                // Move head
                snake.insert(snake.begin(), next);

                if (willGrow) {
                    score += 10;
                    food = randomFoodPos(width, height, snake, rng);
                    tickMs = std::max(minTickMs, tickMs - 3);
                    // snake grows naturally by not popping tail
                    snake.reserve(width * height);
                    (void)growthPerFood;
                } else {
                    // pop tail
                    snake.pop_back();
                }

                if (score > best) best = score;

                render(width, height, snake, food, score, best, tickMs, gameOver);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        // Game over screen
        render(width, height, snake, food, score, best, tickMs, gameOver);

        // Wait for restart / quit
        while (running && gameOver) {
#ifdef _WIN32
            int ch = pollKey();
            if (ch) {
                if (ch == 'q' || ch == 'Q') {
                    running = false;
                    break;
                }
                if (ch == 'r' || ch == 'R') {
                    break; // restart outer loop
                }
            }
#else
            int ch = pollKey();
            if (ch) {
                if (ch == 'q' || ch == 'Q') { running = false; break; }
                if (ch == 'r' || ch == 'R') { break; }
            }
#endif
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }

#ifndef _WIN32
    disableRawMode();
#endif

    clearScreen();
    std::cout << "Thanks for playing!\n";
    return 0;
}

//
