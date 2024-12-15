// Design a PDA that accepts strings in the form WCWR, where W is any string over {0,1},
// and WR is the reverse of W.

#include<stdio.h>
#include<string.h>
#define MAX 100

enum states {q0, q1, qf};  // q0: reading W, q1: reading WR, qf: final state

struct stack {
    char symbols[MAX];
    int top;
} st3;

void push(struct stack* s, char ch) {
    if (s->top < MAX - 1) {
        s->symbols[++(s->top)] = ch;
    } else {
        printf("Stack Full\n");
    }
}

char pop(struct stack* s) {
    if (s->top >= 0) {
        return s->symbols[(s->top)--];
    } else {
        printf("Stack Empty\n");
        return '\0';
    }
}

char get_stack_top(struct stack* s) {
    if (s->top >= 0) {
        return s->symbols[s->top];
    }
    return '\0';  // Return null if stack is empty
}

enum states delta(enum states curr_state, char ch, struct stack* s, int len, int i) {
    if (curr_state == q0) {
        // If we are reading W (first half of the string)
        if (i < len / 2) {
            push(s, ch);
            return q0;  // Stay in q0 as we push W onto the stack
        } else {
            // Move to reading WR (second half)
            return q1;
        }
    } else if (curr_state == q1) {
        // If we are reading WR (reverse of W), pop and check
        char st_top = get_stack_top(s);
        if (ch == st_top) {
            pop(s);  // If current character matches stack top, pop it
            return q1;  // Stay in q1
        } else {
            return curr_state;  // Reject if a mismatch occurs
        }
    }

    // Transition to the final state qf if the stack is empty and all input is processed
    if (curr_state == q1 && s->top == -1) {
        return qf;  // Accept the string if stack is empty
    }

    return curr_state;  // No state change by default
}

int main() {
    st3.top = -1;
    char input[20];
    printf("Enter a binary string: ");
    scanf("%s", input);

    int len = strlen(input);
    int i = 0;
    enum states curr_state = q0;

    // Process each character using delta transitions
    while (i < len) {
        curr_state = delta(curr_state, input[i], &st3, len, i);
        i++;
    }

    // Check final state transition to qf
    curr_state = delta(curr_state, '\0', &st3, len, i);

    if (curr_state == qf) {
        printf("The string %s is accepted\n", input);
    } else {
        printf("The string %s is rejected\n", input);
    }

    return 0;
}
