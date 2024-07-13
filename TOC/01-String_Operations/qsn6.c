//Given a string s,find its substring from index i to length p.Eg :s='abcde' substring i=1,p=3 s1=bcd
#include<conio.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[100], s1[100];
    int i, p, j;
    int length;

    // Input string
    printf("Enter the string: ");
    gets(s);

    // Calculate the length of the string
    length = strlen(s);

    // Input index and length
    printf("Enter the starting index: ");
    scanf("%d", &i);
    printf("Enter the length of the substring: ");
    scanf("%d", &p);

    // Validate the starting index and length
    if (i < 0 || i >= length) {
        printf("Invalid starting index.\n");
    } else if (p < 0 || i + p > length) {
        printf("Invalid length for the substring.\n");
    } else {
        // Extract substring
        for (j = 0; j < p && s[i + j] != '\0'; j++) {
            s1[j] = s[i + j];
        }
        s1[j] = '\0'; // Null-terminate the substring

        // Output the substring
        printf("The substring is: %s\n", s1);
    }

    return 0;
}
