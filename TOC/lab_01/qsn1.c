//Given a string 's'find its length without using library function..
#include <stdio.h>
#include <conio.h>

int main() {
    char s[100];
    int i, length = 0;

    // Input string
    printf("Enter a string: ");
    gets(s);

    // Calculate length
    for(i = 0; s[i] != '\0'; i++) {
        length = length + 1;
    }

    // Output the length
    printf("Length of the string is: %d\n", length);

    getch(); // To hold the console window
    return 0;
}
