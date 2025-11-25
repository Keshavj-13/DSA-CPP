#include <iostream>
#include <vector>
using namespace std;

void merge_arrays(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1);
    vector<int> R(n2);
    
    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void merge_sort(vector<int>& a, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge_arrays(a, l, m, r);
    }
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9};
    merge_sort(a, 0, a.size() - 1);
    for(int x : a) cout << x << " ";
}