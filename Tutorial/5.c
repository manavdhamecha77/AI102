#include <stdio.h>

void decimal_to_binary(int n) {
    // Array to store binary digits
    int binary[32];
    int i = 0;

    // Handle the case when n is 0
    if (n == 0) {
        printf("0");
        return;
    }

    // Loop to convert decimal to binary
    while (n > 0) {
        binary[i] = n % 2;  // Store remainder (0 or 1) in binary array
        n = n / 2;  // Divide the number by 2 for the next iteration
        i++;  // Move to the next index of the array
    }

    // Print binary digits in reverse order
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int num;

    // Input the decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Call the function to convert to binary
    decimal_to_binary(num);

    return 0;
}
