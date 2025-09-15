#include <iostream>

int findMissingNumber(const int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int main() {
    int n;
    std::cout << "Enter n (range is 1 to n, array size is n-1): ";
    std::cin >> n;
    int arr[n - 1]; // Using VLA (variable-length array)
    std::cout << "Enter the sorted array of size " << n - 1 << ": ";
    for (int i = 0; i < n - 1; i++) {
        std::cin >> arr[i];
    }
    int missing = findMissingNumber(arr, n);
    std::cout << "Missing number is: " << missing << std::endl;
    return 0;
}