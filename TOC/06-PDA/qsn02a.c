/*
design a pda that accepts all the string over{0,1} that have equal no of 0's 
and 1 by final state.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

enum states {q0, qf};  // Define initial state q0 and final state qf

struct stack {
    char symbols[MAX];
    int top;
};

void push(struct stack* s, char ch) {
    if (s->top < MAX - 1) {
        s->symbols[++(s->top)] = ch;
    }
}

char pop(struct stack* s) {
    if (s->top >= 0) {
        return s->symbols[(s->top)--];
    }
    return '\0';  // Return null if stack is empty
}

char get_stack_top(struct stack* s) {
    if (s->top >= 0) {
        return s->symbols[s->top];
    }
    return '\0';  // Return null if stack is empty
}

enum states delta(enum states curr_state, char ch, char st_top, struct stack* s) {
    // Delta transition logic: Handle transitions between q0 and qf
    if (curr_state == q0) {
        if (ch == '0') {
            push(s, '0');
            return q0;
        } else if (ch == '1' && st_top == '0') {
            pop(s);
            return q0;
        }
    }
    
    // Transition to final state if the stack is empty after processing input
    if (curr_state == q0 && ch == '\0' && s->top == -1) {
        return qf;  // Transition to final state if stack is empty
    }

    return curr_state;  // Default case, no state change
}

int main() {
    char input[20];
    enum states curr_state = q0;
    struct stack s;
    s.top = -1;

    printf("Enter a binary string: ");
    gets(input);

    int i = 0;
    char ch;
    while ((ch = input[i]) != '\0') {
        char st_top = get_stack_top(&s);

        curr_state = delta(curr_state, ch, st_top, &s);
        i++;
    }

    // Check if the automaton ends in the final state qf
    curr_state = delta(curr_state, '\0', get_stack_top(&s), &s);  // Check for final state

    if (curr_state == qf) {
        printf("String accepted by final state\n");
    } else {
        printf("String rejected\n");
    }

    return 0;
}
