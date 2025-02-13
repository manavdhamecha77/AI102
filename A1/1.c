/*
An array is a bitonic array if all integers from index 0 to index i are sorted in
ascending order, and all subsequent integers from index i+1 to n-1 are sorted in
descending order. Given a bitonic array of n distinct integers, write a C/C++ program to
find the maximum integer in the array in O(log(n)) time.
Example:
Input: n = 6 , A[] ={1 2 4 8 7 6}
Output: 8
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter size of Bitonic array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter Elements of Bitonic Array\n ");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int low = 0;
    int high = n - 1;
    int mid, max;

    while (low <= high) {
        mid = (high + low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            max = arr[mid];
            break;
        } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("\nMaximum Element in Bitonic Array is : %d", max);
    return 0;
    }