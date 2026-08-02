#include <iostream>
#include <vector>

using namespace std;

struct Metrics {
    unsigned long long comparisions = 0;
    unsigned long long ops = 0;
    unsigned long long calls = 0;
    size_t extra_space_bytes = 0;
};

int binarySearchIterative(const vector<int>& A, int key, Metrics& m) {

    m.calls++;
    m.extra_space_bytes = 3 * sizeof(int);

    int low = 0;
    int high = static_cast<int>(A.size()) - 1;
    m.ops += 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        m.ops += 3;
        m.comparisions++;

        if(A[mid] == key) 
            return mid;

        m.comparisions++;

        if(A[mid] < key) {
            low = mid + 1;
            m.ops++;

        } else {
            high = mid - 1;
            m.ops++;
        }
    }

    m.comparisions++;

    return -1;
}

int binarySearchRecursive(const vector<int>& A, int low, int high, int key, Metrics& m) {

    m.calls++;
    m.ops++;
    m.comparisions++;

    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    m.ops += 3;

    m.comparisions++;
    if (A[mid] == key)
        return mid;

    m.comparisions++;
    if (A[mid] < key)
        return binarySearchRecursive(A, mid + 1, high, key, m);

    return binarySearchRecursive(A, low, mid - 1, key, m);
}

    int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    Metrics iterativeMetrics, recursiveMetrics;

    int iterativeResult = binarySearchIterative(A, key, iterativeMetrics);
    int recursiveResult = binarySearchRecursive(A,0, n - 1, key, recursiveMetrics);

    recursiveMetrics.extra_space_bytes = recursiveMetrics.calls * (3 * sizeof(int));

    cout << "\nIterative Binary Search\n";
    cout << "Index   : " << iterativeResult << endl;
    cout << "Coms    : " << iterativeMetrics.comparisions << endl;
    cout << "Ops     : " << iterativeMetrics.ops << endl;
    cout << "Calls : " << iterativeMetrics.calls << endl;
    cout << "Extra Space    : " << iterativeMetrics.extra_space_bytes << " bytes\n";

    cout << "\nRecursive Binary Search\n";
    cout << "Index   : " << recursiveResult << endl;
    cout << "Coms    : " << recursiveMetrics.comparisions << endl;
    cout << "Ops     : " << recursiveMetrics.ops << endl;
    cout << "Calls : " << recursiveMetrics.calls << endl;
    cout << "Extra Space    : " << recursiveMetrics.extra_space_bytes << " bytes";

    return 0;
}
