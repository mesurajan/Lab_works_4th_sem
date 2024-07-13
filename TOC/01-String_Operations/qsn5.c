//Given a string s,find all prefix .eg:abc ,ab,a


#include <stdio.h>
#include <conio.h>

int main() {
    char s[100];
    int i, j, length = 0;

    // Input string
    printf("Enter a string: ");
    gets(s);

    // Calculate length of the string
    for (i = 0; s[i] != '\0'; i++) {
        length++;
    }

    // Print all prefixes
    printf("All prefixes of the string are:\n");
    for (i = length; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("%c", s[j]);
        }
        printf("\n");
    }

    getch(); // To hold the console window
    return 0;
}
