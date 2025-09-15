#include <iostream>

int findMissingNumberBinary(const int arr[], int n) {
    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
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
    int missing = findMissingNumberBinary(arr, n);
    std::cout << "Missing number is: " << missing << std::endl;
    return 0;
}