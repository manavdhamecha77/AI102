/* Find the kth smallest element in an array using quicksort. */
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1); // Random Number 
    swap(arr[randomPivotIndex], arr[high]); // Move pivot to end
    
    int pivot = arr[high];
    int i = low; 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]); // Place pivot in correct position
    return i;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k) 
            return arr[pivotIndex]; // Found the k-th smallest element
        else if (pivotIndex > k) 
            return quickSelect(arr, low, pivotIndex - 1, k); // Search left part
        else 
            return quickSelect(arr, pivotIndex + 1, high, k); // Search right part
    }
    return -1; // Not found
}

int findKthSmallest(vector<int>& arr, int k) {
    if (k < 1 || k > arr.size()) {
        cout << "Invalid k value! Please enter k between 1 and " << arr.size() << "." << endl;
        return -1;
    }
    srand(time(0));
    return quickSelect(arr, 0, arr.size() - 1, k - 1); 
}

int main() {

    srand(time(0)); // Seed for random pivot selection
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthSmallest(arr, k);
    if (result != -1)
        cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
