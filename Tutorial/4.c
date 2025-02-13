#include <stdio.h>

// Function to rotate the array by k positions to the left
void rotate_left(int arr[], int n, int k) {
    int temp[n];  // Auxiliary array to store rotated elements
    int i;
    
    // Adjust k to ensure it's within the bounds of the array
    k = k % n;
    
    // Copy the elements after k positions to the beginning of the temp array
    for(i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    
    // Copy the rotated elements back to the original array
    for(i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// Function to rotate the array by k positions to the right
void rotate_right(int arr[], int n, int k) {
    int temp[n];  // Auxiliary array to store rotated elements
    int i;
    
    // Adjust k to ensure it's within the bounds of the array
    k = k % n;
    
    // Copy the elements before k positions to the end of the temp array
    for(i = 0; i < n; i++) {
        temp[i] = arr[(i - k + n) % n];
    }
    
    // Copy the rotated elements back to the original array
    for(i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k, i;
    char direction;
    
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input elements of the array
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the number of positions to rotate
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);
    
    // Input the direction of rotation ('L' for left, 'R' for right)
    printf("Enter the direction of rotation (L for left, R for right): ");
    scanf(" %c", &direction);
    
    // Rotate the array based on user input
    if(direction == 'L' || direction == 'l') {
        rotate_left(arr, n, k);
    } else if(direction == 'R' || direction == 'r') {
        rotate_right(arr, n, k);
    } else {
        printf("Invalid direction!\n");
        return 1;
    }
    
    // Print the rotated array
    printf("Array after rotation:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
