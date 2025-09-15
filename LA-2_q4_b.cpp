#include <iostream>

void manual_swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int manual_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str[100];
    std::cout << "Enter a string: ";
    std::cin >> str;
    int n = manual_strlen(str);
    for (int i = 0; i < n / 2; i++) {
        manual_swap(str[i], str[n - i - 1]);
    }
    std::cout << "Reversed string: " << str << std::endl;
    return 0;
}