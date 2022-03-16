#include <iostream>

using namespace std;

int findPosFirstNotNegativeEle(int ar[], int n);
void squareEle(int ar[], int n);
void mergeArray(int ar[], int low, int mid, int high);
void sortArray(int ar[], int low, int high);
void printArray(int ar[], int n);

int main() {
    // int n = 5;
    // int ar[] = { -4, -1, 0, 3, 9 };

    // int n = 5;
    // int ar[] = { -7, -3, 2, 3, 11 };

    int n = 7;
    int ar[] = { -8, -4, 3, 6, 7, 9, 12 };

    int pos = findPosFirstNotNegativeEle(ar, n);
    if(pos == -1) {
        return 0;
    }
    squareEle(ar, n);
    sortArray(ar, 0, n - 1);
    cout << "Array after using merge sort: ";
    printArray(ar, n);

    return 0;
}

int findPosFirstNotNegativeEle(int ar[], int n) {
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(ar[i] >= 0) {
            return i;
        }
    }
    return pos;
}

void squareEle(int ar[], int n) {
    for(int i = 0; i < n; i++) {
        ar[i] = ar[i] * ar[i];
    }
}

void mergeArray(int ar[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* leftSubArray = new int[n1];
    int* rightSubArray = new int[n2];

    for(int i = 0; i < n1; i++) {
        leftSubArray[i] = ar[low + i];
    }
    for(int i = 0; i < n2; i++) {
        rightSubArray[i] = ar[mid + 1 + i];
    }

    int i = 0; 
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if(leftSubArray[i] < rightSubArray[j]) {
            ar[k] = leftSubArray[i];
            k++;
            i++;
        }
        else {
            ar[k] = rightSubArray[j];
            k++;
            j++;
        }
    }
    while (i < n1) {
        ar[k] = leftSubArray[i];
        k++;
        i++;
    }
    while (j < n2) {
        ar[k] = rightSubArray[j];
        k++;
        j++;
    }
}

void sortArray(int ar[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        sortArray(ar, low, mid);
        sortArray(ar, mid + 1, high);
        mergeArray(ar, low, mid, high);
    }
}

void printArray(int ar[], int n) {
    for(int i = 0; i < n; i++) {
        cout << ar[i] << endl;
    }
}