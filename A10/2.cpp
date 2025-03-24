/*
Let A[n] be an array of n distinct integers. If i < j and A[i] > A[j], then the pair (i, j) Is
called an inversion of A. Write a C/C++ program that determines the number of
Inversions in any permutation on n elements in O(nlogn) worst-case time. (Hint: Modify
merge sort)
Example: A = {4, 1, 3, 2} output is 4
*/

#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    int inv_count = mergeSortAndCount(arr, temp, left, mid);
    inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
    inv_count += mergeAndCount(arr, temp, left, mid, right);
    
    return inv_count;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Inversions: " << countInversions(arr, n) << endl;
    return 0;
}
