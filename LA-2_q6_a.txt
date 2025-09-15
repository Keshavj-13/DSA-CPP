#include <iostream>

struct Triplet {
    int row, col, val;
};

void transpose(Triplet mat[], Triplet result[], int n) {
    result[0].row = mat[0].col;
    result[0].col = mat[0].row;
    result[0].val = mat[0].val;
    int k = 1;
    for (int i = 0; i < mat[0].col; i++) {
        for (int j = 1; j <= mat[0].val; j++) {
            if (mat[j].col == i) {
                result[k].row = mat[j].col;
                result[k].col = mat[j].row;
                result[k].val = mat[j].val;
                k++;
            }
        }
    }
}

int main() {
    Triplet mat[5] = {{3,3,4},{0,0,1},{0,2,2},{1,1,3},{2,0,4}};
    Triplet result[5];
    transpose(mat, result, 5);
    std::cout << "Transpose (triplet):\n";
    for (int i = 0; i < 5; i++) {
        std::cout << result[i].row << " " << result[i].col << " " << result[i].val << std::endl;
    }
    return 0;
}