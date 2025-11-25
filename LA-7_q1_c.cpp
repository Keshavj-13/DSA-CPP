#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9};
    bubble_sort(a);
    for(int x : a) cout << x << " ";
}