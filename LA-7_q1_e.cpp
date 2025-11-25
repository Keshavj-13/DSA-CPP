#include <iostream>
#include <vector>
using namespace std;

int partition_point(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    int temp = a[i];
    a[i] = a[high];
    a[high] = temp;
    return i;
}

void quick_sort(vector<int>& a, int low, int high) {
    if(low < high) {
        int pi = partition_point(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9};
    quick_sort(a, 0, a.size() - 1);
    for(int x : a) cout << x << " ";
}