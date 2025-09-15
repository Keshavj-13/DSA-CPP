#include <iostream>

struct Triplet {
    int row, col, val;
};

// For simplicity, assumes square matrices and small size
void multiply(Triplet a[], Triplet b[], Triplet result[], int n1, int n2) {
    int n = a[0].row;
    int temp[10][10] = {0};
    for (int i = 1; i <= a[0].val; i++) {
        temp[a[i].row][a[i].col] = a[i].val;
    }
    for (int i = 1; i <= b[0].val; i++) {
        temp[b[i].row][b[i].col] += b[i].val;
    }
    // Convert to triplet
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] != 0) {
                result[k++] = {i, j, temp[i][j]};
            }
        }
    }
    result[0] = {n, n, k-1};
}

int main() {
    Triplet a[4] = {{3,3,3},{0,0,1},{1,1,2},{2,2,3}};
    Triplet b[3] = {{3,3,2},{0,2,4},{2,0,5}};
    Triplet result[10];
    multiply(a, b, result, 4, 3);
    std::cout << "Multiplication (triplet):\n";
    for (int i = 0; i <= result[0].val; i++) {
        std::cout << result[i].row << " " << result[i].col << " " << result[i].val << std::endl;
    }
    return 0;
}