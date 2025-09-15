#include <iostream>

class LowerTriangularMatrix {
    int *A;
    int n;
public:
    LowerTriangularMatrix(int size) {
        n = size;
        A = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i >= j) A[(i*(i-1))/2 + (j-1)] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[(i*(i-1))/2 + (j-1)];
        else return 0;
    }
    ~LowerTriangularMatrix() { delete[] A; }
};

int main() {
    LowerTriangularMatrix lm(4);
    lm.set(1,1,1); lm.set(2,1,2); lm.set(2,2,3); lm.set(3,1,4); lm.set(3,2,5); lm.set(3,3,6); lm.set(4,1,7); lm.set(4,2,8); lm.set(4,3,9); lm.set(4,4,10);
    std::cout << "Lower Triangular Matrix:\n";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            std::cout << lm.get(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}