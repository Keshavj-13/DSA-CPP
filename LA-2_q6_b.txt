#include <iostream>

struct Triplet {
    int row, col, val;
};

void add(Triplet a[], Triplet b[], Triplet result[], int n1, int n2) {
    result[0] = a[0];
    int i=1, j=1, k=1;
    while(i<=a[0].val && j<=b[0].val) {
        if(a[i].row == b[j].row && a[i].col == b[j].col) {
            result[k] = {a[i].row, a[i].col, a[i].val + b[j].val};
            i++; j++; k++;
        } else if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
    while(i<=a[0].val) result[k++] = a[i++];
    while(j<=b[0].val) result[k++] = b[j++];
    result[0].val = k-1;
}

int main() {
    Triplet a[4] = {{3,3,3},{0,0,1},{1,1,2},{2,2,3}};
    Triplet b[3] = {{3,3,2},{0,2,4},{2,0,5}};
    Triplet result[7];
    add(a, b, result, 4, 3);
    std::cout << "Addition (triplet):\n";
    for (int i = 0; i <= result[0].val; i++) {
        std::cout << result[i].row << " " << result[i].col << " " << result[i].val << std::endl;
    }
    return 0;
}