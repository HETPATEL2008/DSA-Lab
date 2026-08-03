#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>& A) {

    int n = A.size();

    for(int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < n; j++) {

            if(A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        int temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main() {

    vector<int> A = {29, 72, 98, 13, 87, 66, 52, 51, 36};

    selectionSort(A);

    cout << "Sorted Array:\n";
    for(int x : A) {
        cout << x << " ";
    }

    return 0;
}
