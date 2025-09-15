#include <iostream>

class UpperTriangularMatrix {
    int *A;
    int n;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        A = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }
    void set(int i, int j, int x) {
        if (i <= j) A[(j*(j-1))/2 + (i-1)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[(j*(j-1))/2 + (i-1)];
        else return 0;
    }
    ~UpperTriangularMatrix() { delete[] A; }
};

int main() {
    UpperTriangularMatrix um(4);
    um.set(1,1,1); um.set(1,2,2); um.set(1,3,3); um.set(1,4,4);
    um.set(2,2,5); um.set(2,3,6); um.set(2,4,7);
    um.set(3,3,8); um.set(3,4,9);
    um.set(4,4,10);
    std::cout << "Upper Triangular Matrix:\n";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            std::cout << um.get(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}