#include <iostream>

using namespace std;

void findLongestConsecutiveOnes(int ar[], int n);
int findLongestConsecutiveOnes_DP(int ar[], int n);

int main() {
    // int n = 6;
    // int ar[] = {1, 0, 1, 1, 0, 1};

    int n = 11;
    int ar[] = {1,1,1,0,0,1,1,1,1,0,1};

    findLongestConsecutiveOnes(ar, n); // normal solution

    int maxLength = findLongestConsecutiveOnes_DP(ar, n); // DP solution
    cout << "The longest consecutive ones: " << maxLength << endl;

    return 0;
}

// normal way
void findLongestConsecutiveOnes(int ar[], int n) {
    int count = 0;
    int idx_01 = 0;
    int idx_02 = 0;
    int max = 0;
    
    for(int i = 0; i < n - 1; i++) {
        if(ar[i] == 1 && ar[i + 1] == 1) {
            count++;
        }
        else {
            count = 1;
        }
        if(count > max) {
            max = count;
            idx_01 = i + 1;
            idx_02 = i - count + 2;
        }
    }

    cout << "The longest '1' array: ";
    for(int i = idx_02; i <= idx_01; i++) {
        cout << ar[i] << " ";
    }

    cout << endl;
    cout << (idx_01 - idx_02) + 1 << endl;
}


// DYNAMIC PROGRAMMING WAY
int findLongestConsecutiveOnes_DP(int ar[], int n) {
    int count = 0;
    int max = 0;

    for(int i = 0; i < n; i++) {
        if(ar[i] == 1) {
            count++;
        }
        else {
            count = 0;
        }
        max = (max > count) ? max : count;
    }
    return max;
}