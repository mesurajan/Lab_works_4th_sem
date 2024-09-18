// DFA to Detect Single-line and Multi-line Comments

#include <stdio.h>
#include <string.h>

// Function to check if a string is a comment
int isComment(char *str) {
    int len = strlen(str);
    
    // Check for single-line comment starting with "//"
    if (str[0] == '/' && str[1] == '/') {
        return 1;
    }
    
    // Check for multi-line comment starting with "/*" and ending with "*/"
    if (str[0] == '/' && str[1] == '*' && str[len - 2] == '*' && str[len - 1] == '/') {
        return 1;
    }
    
    return 0;
}

int main() {
    char str[200];
    
    // Input the string (a potential comment)
    printf("Enter a comment: ");
    fgets(str, sizeof(str), stdin);
    
    // Check if the string is a comment
    if (isComment(str)) {
        printf("This is a valid comment.\n");
    } else {
        printf("This is not a valid comment.\n");
    }
    
    return 0;
}
