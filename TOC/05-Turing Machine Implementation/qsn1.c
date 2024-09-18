// Turing Machine for L = {0^n 1^n}


#include <stdio.h>
#include <string.h>

// Function to check if the input is in the form 0^n 1^n
int isLanguageAccepted(char *str) {
    int len = strlen(str);
    int i = 0;

    // Count the number of 0's
    while (i < len && str[i] == '0') {
        i++;
    }

    // After 0's, there should be an equal number of 1's
    int numZeros = i;
    while (i < len && str[i] == '1') {
        i++;
    }

    int numOnes = i - numZeros;

    // The input is accepted if the number of 0's is equal to the number of 1's
    return (numZeros == numOnes && i == len);
}

int main() {
    char str[100];

    // Input the binary string
    printf("Enter a binary string (0's followed by 1's): ");
    scanf("%s", str);

    // Check if the input is accepted by the Turing Machine
    if (isLanguageAccepted(str)) {
        printf("The string '%s' is accepted by the Turing Machine (L = 0^n 1^n).\n", str);
    } else {
        printf("The string '%s' is NOT accepted by the Turing Machine.\n", str);
    }

    return 0;
}
