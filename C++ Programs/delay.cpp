#include <iostream>

int main() {
    std::cout << "This will print immediately." << std::endl;
    
    // Delay for 2 seconds
    Sleep(2000); // Sleep function takes milliseconds
    
    std::cout << "This will print after a 2-second delay." << std::endl;
    
    return 0;
}

