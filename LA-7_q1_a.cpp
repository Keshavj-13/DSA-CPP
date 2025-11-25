#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        int m = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[m]) m = j;
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9};
    selection_sort(a);
    for(int x : a) cout << x << " ";
}