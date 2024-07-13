//Given two strings s1 and s3 displays the concatenated string s3=s1.s2

#include <stdio.h>
#include <conio.h>

int main() {
    char s1[100], s2[100], s3[250]; // s3 should be large enough to hold both s1 and s2
    int i, j;

    // Input first string
    printf("Enter the first string: ");
    gets(s1);

    // Input second string
    printf("Enter the second string: ");
    gets(s2);

    // Copy first string to s3
    for(i = 0; s1[i] != '\0'; i++) {
        s3[i] = s1[i];
    }

    // Concatenate second string to s3
    for(j = 0; s2[j] != '\0'; j++, i++) {
        s3[i] = s2[j];
    }
    s3[i] = '\0'; // Null-terminate the concatenated string

    // Output the concatenated string
    printf("Concatenated string is: %s\n", s3);

    getch(); // To hold the console window
    return 0;
}
