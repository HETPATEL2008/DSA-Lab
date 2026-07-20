#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& A) {

    int n = A.size();

    for(int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {

    vector<int> A = {9, 7, 6, 15, 17, 5, 10, 11};

    insertionSort(A);

    cout << "Sorted Array:\n";
    for(int x : A) {
        cout << x << " ";
    }

    return 0;
}
