/* 
Given an array of non-negative integers, implement the Counting Sort algorithm to sort 
the array in ascending order.
*/

#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) 
        if (arr[i] > maxVal) maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++) 
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) {
            arr[index++] = i;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements (non-negative integers): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
