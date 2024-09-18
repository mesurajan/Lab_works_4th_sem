// Turing Machine to Complement a Binary String

#include <stdio.h>
#include <string.h>

// Function to complement a binary string
void complementBinaryString(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '0') {
            str[i] = '1';  // Replace 0 with 1
        } else if (str[i] == '1') {
            str[i] = '0';  // Replace 1 with 0
        }
    }
}

int main() {
    char str[100];

    // Input the binary string
    printf("Enter a binary string: ");
    scanf("%s", str);

    // Complement the binary string
    complementBinaryString(str);

    // Output the complemented string
    printf("The complement of the binary string is: %s\n", str);

    return 0;
}
