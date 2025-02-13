#include <stdio.h>

// Function to remove duplicates
int remove_duplicates(int arr[], int n) {
    int i, j, k;
    
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            // If duplicate element is found
            if(arr[i] == arr[j]) {
                // Shift elements to the left
                for(k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;  // Reduce the size of the array
                j--;  // Adjust j to recheck the current position
            }
        }
    }
    return n; // Return the new size of the array
}

int main() {
    int n, i;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input elements of the array
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to remove duplicates
    n = remove_duplicates(arr, n);

    // Print the array after removing duplicates
    printf("Array after removing duplicates:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
