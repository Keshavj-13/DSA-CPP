#include <iostream>

int manual_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void manual_strcpy(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int main() {
    int n;
    std::cout << "Enter number of strings: ";
    std::cin >> n;
    char arr[100][100];
    std::cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (manual_strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                manual_strcpy(temp, arr[j]);
                manual_strcpy(arr[j], arr[j + 1]);
                manual_strcpy(arr[j + 1], temp);
            }
        }
    }
    
    std::cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}