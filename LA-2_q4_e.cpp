#include <iostream>

int main() {
    char c;
    std::cout << "Enter an uppercase character: ";
    std::cin >> c;
    if (c >= 'A' && c <= 'Z')
        c = c + 32;
    std::cout << "Lowercase: " << c << std::endl;
    return 0;
}