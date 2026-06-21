#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            std::cout << "Escape key pressed!" << std::endl;
            break;
        }
		if (GetAsyncKeyState(VK_RETURN)) {
            std::cout << "Escape key pressed2!" << std::endl;
            break;
        }
        // Add more keys as needed
    }
    return 0;
}

