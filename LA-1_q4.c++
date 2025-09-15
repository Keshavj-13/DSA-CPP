#include <iostream>
using namespace std;

int main(){
    // (a) reverse the  array
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // b. Find the matrix multiplication
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2] = {0};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    cout << "Matrix multiplication result:\n";  
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // c. Find the Transpose of a Matrix
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "Transpose of the matrix:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
    return 0; 
}