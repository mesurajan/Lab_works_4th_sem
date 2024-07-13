//Given a string s,find all suffix .eg :abcd,bcd,cd,d.

#include <stdio.h>
#include <conio.h>

int main() {
    char s[100];
    int i, length = 0;

    // Input string
    printf("Enter a string: ");
    gets(s);

    // Calculate length of the string
    for (i = 0; s[i] != '\0'; i++) {
        length++;
    }

    // Print all suffixes
    printf("All suffixes of the string are:\n");
    for (i = 0; i < length; i++) {
        printf("%s\n", s + i);
    }

    getch(); // To hold the console window
    return 0;
}
