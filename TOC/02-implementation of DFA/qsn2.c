//Design a DFA that accepts the stringd that contains '1011' as substrings.Also implement it using c
#include<stdio.h>

enum states {q0, q1, q2, q3, qf, qd};
enum states delta(enum states, char);

int main() {
    char input[100];
    enum states curr_state = q0;
    int i = 0;

    printf("\nEnter a binary string: ");
    gets(input);
    char ch = input[i];

    while (ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if (curr_state == qf) {
        printf("Provided string is Accepted");
    } else {
        printf("Provided string is Rejected");
    }

    return 0;
}

enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch (s) {
        case q0:
            if (ch == '1')
                curr_state = q1;
            else
                curr_state = q0;
            break;
        case q1:
            if (ch == '0')
                curr_state = q2;
            else
                curr_state = q1;
            break;
        case q2:
            if (ch == '1')
                curr_state = q3;
            else
                curr_state = q0;
            break;
        case q3:
            if (ch == '1')
                curr_state = qf;
            else
                curr_state = q2;
            break;
        case qf:
            curr_state = qf;
            break;
        case qd:
            curr_state = qd;
            break;
    }
    return curr_state;
}
