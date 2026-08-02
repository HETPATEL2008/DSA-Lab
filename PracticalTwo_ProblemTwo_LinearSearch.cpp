#include <iostream>
#include <vector>

using namespace std;

struct Metrics {
    unsigned long long comparisions = 0;
    unsigned long long ops = 0;
    unsigned long long calls = 0;
    size_t extra_space_bytes = 0;
};

int linearSearchIterative(const vector<int>& A, int key, Metrics& m) {
    m.calls++;
    m.extra_space_bytes = sizeof(int);

    for(int i = 0; i < (int)A.size(); i++) {
        m.ops++;
        m.comparisions++;
        if(A[i] == key)
            return i;
    }

    return -1;
}

int linearSearchRecursive(const vector<int>& A, int key, int index, Metrics& m) {
    m.calls++;
    m.ops++;
    m.comparisions++;

    if(index >= (int)A.size()) 
        return -1;

    m.comparisions++;

    if(A[index] == key)
        return index;

    return linearSearchRecursive(A, key, index + 1, m);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Metrics iterativeMetrics, recursiveMetrics;

    int iterativeResult = linearSearchIterative(A, key, iterativeMetrics);
    int recursiveResult = linearSearchRecursive(A, key, 0, recursiveMetrics);

    cout << "\nIterative Linear Search\n";
    cout << "Index   : " << iterativeResult << endl;
    cout << "Comps    : " << iterativeMetrics.comparisions << endl;
    cout << "Ops     : " << iterativeMetrics.ops << endl;
    cout << "Calls : " << iterativeMetrics.calls << endl;
    cout << "Extra Space    : " << iterativeMetrics.extra_space_bytes << " bytes\n";

    cout << "\nRecursive Linear Search\n";
    cout << "Index   : " << recursiveResult << endl;
    cout << "Comps    : " << recursiveMetrics.comparisions << endl;
    cout << "Ops     : " << recursiveMetrics.ops << endl;
    cout << "Calls : " << recursiveMetrics.calls << endl;
    cout << "Extra Space    : " << recursiveMetrics.extra_space_bytes << " bytes\n";

    return 0;
}
