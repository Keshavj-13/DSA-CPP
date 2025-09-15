#include <iostream>

int main() {
    char str1[200], str2[100];
    std::cout << "Enter first string: ";
    std::cin >> str1;
    std::cout << "Enter second string: ";
    std::cin >> str2;
    
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    int len2 = 0;
    while (str2[len2] != '\0') {
        len2++;
    }
    
    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
    
    std::cout << "Concatenated string: " << str1 << std::endl;
    return 0;
}