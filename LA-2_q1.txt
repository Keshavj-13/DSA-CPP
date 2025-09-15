#include <iostream>

int bins(int *arr, int tar, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == tar) {
            return mid;
        }
        if (arr[mid] > tar) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int tar = 3;
    int a = bins(arr, tar, n);
    std::cout << a;
    return 0;
}