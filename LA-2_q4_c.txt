#include <iostream>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char str[100], res[100];
    std::cout << "Enter a string: ";
    std::cin >> str;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            res[j++] = str[i];
        }
    }
    res[j] = '\0';
    std::cout << "String after deleting vowels: " << res << std::endl;
    return 0;
}