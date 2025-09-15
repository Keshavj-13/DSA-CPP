#include <iostream>

int countInversions(int arr[], int n) {
    int inv = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) inv++;
        }
    }
    return inv;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    int* arr = new int[n];
    std::cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    int inv = countInversions(arr, n);
    std::cout << "Number of inversions: " << inv << std::endl;
    delete[] arr; // Free the dynamically allocated memory
    return 0;
}