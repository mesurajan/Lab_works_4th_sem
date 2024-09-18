// Turing Machine for Binary Addition

#include <stdio.h>
#include <string.h>

// Function to add two binary numbers
void binaryAddition(char *num1, char *num2, char *result) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0, k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0) ? num1[i] - '0' : 0;
        int bit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result[k++] = (sum % 2) + '0';  // Store the sum (bit)
        carry = sum / 2;  // Compute the carry

        i--;
        j--;
    }

    result[k] = '\0';  // Null-terminate the result string

    // Reverse the result string to get the correct order
    for (int l = 0; l < k / 2; l++) {
        char temp = result[l];
        result[l] = result[k - l - 1];
        result[k - l - 1] = temp;
    }
}

int main() {
    char num1[100], num2[100], result[100];

    // Input the binary numbers
    printf("Enter the first binary number: ");
    scanf("%s", num1);
    printf("Enter the second binary number: ");
    scanf("%s", num2);

    // Perform binary addition
    binaryAddition(num1, num2, result);

    // Output the result
    printf("The result of binary addition is: %s\n", result);

    return 0;
}
