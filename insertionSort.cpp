#include <iostream>
using namespace std;




void insertionSort(int A[], int n){
    int key, j;
    for (int i = 1; i <= n-1; i++){
        key = A[i];
        j = A[i-1];
        while(j >= 0 && key < j){                // 3, 5, 8, 4, 1
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void printArr(int A[], int n){
    for (int i = 0; i < n ; i++){
        cout << A[i];
    }
}

int main () {
    int A[] = {3 , 9 , 55 , 90 , 1 , 0 , 32 , 45 , 88};
    int n = 9;
    // cout << "before insertion sort " << endl;
    // printArr(A, n);
    insertionSort(A, n);
    // cout << " after insertion sort " << endl;
    // printArr(A, n);
    return 0;
}