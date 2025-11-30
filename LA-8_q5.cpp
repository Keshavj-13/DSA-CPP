#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Heapify for max heap (for increasing sort)
void heapifyDown(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

// Heapify for min heap (for decreasing sort)
void heapifyDownMin(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapifyDownMin(arr, n, smallest);
    }
}

// Heapsort - increasing order (using max heap)
void heapSortIncreasing(int arr[], int n){
    // Build max heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapifyDown(arr, n, i);
    }

    // Extract elements from heap one by one
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}

// Heapsort - decreasing order (using min heap)
void heapSortDecreasing(int arr[], int n){
    // Build min heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapifyDownMin(arr, n, i);
    }

    // Extract elements from heap one by one
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapifyDownMin(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Heapsort increasing
    int arr1[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    heapSortIncreasing(arr1, n);
    cout << "Heapsort (Increasing): ";
    printArray(arr1, n);

    // Heapsort decreasing
    int arr2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    heapSortDecreasing(arr2, n);
    cout << "Heapsort (Decreasing): ";
    printArray(arr2, n);

    return 0;
}
