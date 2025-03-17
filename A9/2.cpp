#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> v1(n1);
    vector<int> v2(n2);

    // Copy elements into left and right subarrays
    for (int i = 0; i < n1; i++) {
        v1[i] = v[low + i];
    }

    for (int i = 0; i < n2; i++) {
        v2[i] = v[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            v[k++] = v1[i++];
        } else {
            v[k++] = v2[j++];
        }
    }

    while (i < n1) {
        v[k++] = v1[i++];
    }

    while (j < n2) {
        v[k++] = v2[j++];
    }
}

void mergesort(vector<int>& v, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2; // Correct mid calculation

        // Recursively sort both halves
        mergesort(v, low, mid);
        mergesort(v, mid + 1, high);

        // Merge sorted halves
        merge(v, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter elements of Array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    mergesort(v, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
