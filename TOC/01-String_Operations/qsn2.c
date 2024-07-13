//Given string 's'prints its reverse string s1.
#include <stdio.h>
#include <conio.h>

int main() {
    char s[100], s1[100];
    int i, length = 0;

    // Input string
    printf("Enter a string: ");
    gets(s);

    // Calculate length of the string
    for(i = 0; s[i] != '\0'; i++) {
        length++;
    }

    // Reverse the string
    for(i = 0; i < length; i++) {
        s1[i] = s[length - i - 1];
    }
    s1[length] = '\0'; // Null-terminate the reversed string

    // Output the reversed string
    printf("Reversed string is: %s\n", s1);

    getch(); // To hold the console window
    return 0;
}
