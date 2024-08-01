// Implement NFA over alphabets {0,1} that accepts strings ending with "01"

#include <stdio.h>
#include <string.h>

char input[20];
int l;
int flag;

void s(int i) {
    if (i == l) {
        // If we've reached the end of the string and the last character was '1', we accept
        flag = 1;
    }
}

void q(int i) {
    if (i < l) {
        if (input[i] == '1') {
            s(i + 1);
        } else {
            q(i + 1);
        }
    }
}

void p(int i) {
    if (i < l) {
        if (input[i] == '0') {
            q(i + 1);
        } else {
            p(i + 1);
        }
    }
}

int main() {
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    l = strlen(input);

    // Remove newline character if present
    if (l > 0 && input[l - 1] == '\n') {
        input[l - 1] = '\0';
        l--;
    }

    flag = 0;

    // Start the check from the beginning of the string
    p(0);

    if (flag == 1)
        printf("The string is accepted.\n");
    else
        printf("The string is not accepted.\n");

    return 0;
}
