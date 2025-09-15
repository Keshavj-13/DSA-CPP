#include <iostream>

class DiagonalMatrix {
    int *A;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        A = new int[n];
        for (int i = 0; i < n; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        else return 0;
    }
    ~DiagonalMatrix() { delete[] A; }
};

int main() {
    DiagonalMatrix dm(4);
    dm.set(1,1,5); dm.set(2,2,8); dm.set(3,3,9); dm.set(4,4,12);
    std::cout << "Diagonal Matrix:\n";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            std::cout << dm.get(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}