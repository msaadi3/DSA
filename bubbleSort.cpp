#include <iostream>
#include <string>
using namespace std;

// bubble sort is a sorting algoritham
// time complexity of bubble sort is O(n2) but for already sorted / adaptive bubble sort algoritham is O(n)
// bubble sort isn't a recursive algoritham
// bubble sort is a stable algoritham because order of same occurance/elements remain same
// bubble sort isn't adaptive algoritham by default but it can be made adaptive that means if array is already sorted it can benefit off of it through some special function/coding and time complexity for already sorted / adaptive bubble sort algoritham is O(n)


void printArr(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
}

void bubbleSort(int A[], int n){
    for (int i = 0; i < n-1; i++){    // for number of passes 
        for(int j = 0; j < n-1-i; j++){     // for number of comparisons/swaps in each pass
            if(A[j] > A[j+1]){
            int temp;
            temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
            }
        }
    }
}

// FOR ADAPTIVE     
void bubbleSortAdaptive(int A[], int n){
    for (int i = 0; i < n-1; i++){    // for number of passes 
        for(int j = 0; j < n-1-i; j++){     // for number of comparisons/swaps in each pass
            if(A[j] > A[j+1]){
            int temp;
            temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
            }
        }
    }
}


int main(){
    int A[] = {12,54,65,7,23,9};
    int n = 6; 
    cout << " array before bubble sort " << endl;
    printArr(A , n);
    cout <<  " array after bubble sort " << endl;
    bubbleSort(A, n);
    printArr(A , n);
    
    
}