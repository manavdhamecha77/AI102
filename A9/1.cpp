#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
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

    bubbleSort(v);

    cout << "Sorted Array: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
