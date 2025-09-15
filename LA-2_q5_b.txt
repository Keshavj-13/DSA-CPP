#include <iostream>

class TridiagonalMatrix {
    int *A;
    int n;
public:
    TridiagonalMatrix(int size) {
        n = size;
        A = new int[3*n-2];
        for (int i = 0; i < 3*n-2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i-j == 1) A[i-2] = x;
        else if (i-j == 0) A[n-1+i-1] = x;
        else if (i-j == -1) A[2*n-1+i-1] = x;
    }
    int get(int i, int j) {
        if (i-j == 1) return A[i-2];
        else if (i-j == 0) return A[n-1+i-1];
        else if (i-j == -1) return A[2*n-1+i-1];
        else return 0;
    }
    ~TridiagonalMatrix() { delete[] A; }
};

int main() {
    TridiagonalMatrix tm(4);
    tm.set(1,1,4); tm.set(2,2,5); tm.set(3,3,6); tm.set(4,4,7);
    tm.set(2,1,1); tm.set(3,2,2); tm.set(4,3,3);
    tm.set(1,2,8); tm.set(2,3,9); tm.set(3,4,10);
    std::cout << "Tridiagonal Matrix:\n";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            std::cout << tm.get(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}