//checking keywords and identifiers

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "int", "long", "register", "return", "short", "signed", "sizeof", 
    "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Function to check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a valid identifier using DFA
int isValidIdentifier(char *str) {
    // Check if the first character is a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    
    // Check the remaining characters (alphanumeric or underscore)
    for (int i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    
    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if the string is a keyword
    if (isKeyword(str)) {
        printf("'%s' is a keyword in C.\n", str);
    } else if (isValidIdentifier(str)) {
        printf("'%s' is a valid identifier.\n", str);
    } else {
        printf("'%s' is not a valid identifier.\n", str);
    }
    
    return 0;
}
