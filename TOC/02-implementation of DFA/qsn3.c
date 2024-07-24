//Design a DFA that accepts strings of 0 and 1 which contains either 00 or 11 as substrings .Also implement it
#include <stdio.h>

enum states {q0, q1, q2, q3, q4};
enum states delta(enum states, char);

int main() {
    char input[100];
    enum states curr_state = q0;
    int i = 0;

    printf("Enter a binary string: ");
    gets(input);
    char ch = input[i];

    while (ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if (curr_state == q3 || curr_state == q4) {
        printf("Provided string is Accepted\n");
    } else {
        printf("Provided string is Rejected\n");
    }

    return 0;
}

enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch (s) {
        case q0:
            if (ch == '0')
                curr_state = q1;
            else
                curr_state = q2;
            break;
        case q1:
            if (ch == '0')
                curr_state = q3;
            else
                curr_state = q2;
            break;
        case q2:
            if (ch == '1')
                curr_state = q4;
            else
                curr_state = q1;
            break;
        case q3:
        case q4:
            curr_state = s;
            break;
    }
    return curr_state;
}
