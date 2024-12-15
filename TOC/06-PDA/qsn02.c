/*
design a pda that accepts all the string over{0,1} that have equal no of 0's 
and 1 by empty state.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100

enum states {q0};  // Assuming single state q0 for simplicity

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

enum states delta(enum states curr_state, char ch, char st_top) {
    // Delta transition logic: Assuming PDA pushes '0' and pops '1'
    if (curr_state == q0) {
        if (ch == '0') {
            return q0;  // Stay in q0, push to stack
        } else if (ch == '1' && st_top == '0') {
            return q0;  // Stay in q0, pop from stack
        }
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
    char ch = 'e';
    while (input[i] != '\0') {
        ch = input[i];
        char st_top = get_stack_top(&s);

        curr_state = delta(curr_state, ch, st_top);

        if (ch == '0') {
            push(&s, '0');
        } else if (ch == '1') {
            pop(&s);
        }
        i++;
    }

    if (s.top == -1) {
        printf("String accepted by empty stack\n");
    } else {
        printf("String rejected\n");
    }

    return 0;
}
