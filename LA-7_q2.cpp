#include <iostream>
#include <vector>
using namespace std;

void improved_selection_sort(vector<int>& a) {
    int left = 0;
    int right = a.size() - 1;
    
    while(left < right) {
        int mn = left;
        int mx = right;
        
        for(int i = left; i <= right; i++) {
            if(a[i] < a[mn]) mn = i;
            if(a[i] > a[mx]) mx = i;
        }
        
        int temp = a[left];
        a[left] = a[mn];
        a[mn] = temp;
        
        if(mx == left) mx = mn;
        
        temp = a[right];
        a[right] = a[mx];
        a[mx] = temp;
        
        left++;
        right--;
    }
}

int main() {
    vector<int> a = {5, 2, 8, 1, 9, 3};
    improved_selection_sort(a);
    for(int x : a) cout << x << " ";
}