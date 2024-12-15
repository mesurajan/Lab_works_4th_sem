/* Design a PDA that accepts strings where the number of 0’s 
is followed by the same number of 1’s.*/

#include<stdio.h>
#define MAX 100

enum state {q0, q1, q2};
void push(char ch);
char get_stack_top();
void pop();
enum state delta(enum state s, char ch, char st_top);

struct stack {
    char symbols[MAX];
    int top;
} st;

void push(char ch) {
    if (st.top < MAX - 1) {
        st.symbols[++st.top] = ch;
    } else {
        printf("Stack Full\n");
    }
}

char get_stack_top() {
    if (st.top > -1) {
        return st.symbols[st.top];
    }
    return '\0';
}

void pop() {
    if (st.top > -1) {
        st.symbols[st.top--] = '\0';
    } else {
        printf("Stack Empty\n");
    }
}

enum state delta(enum state s, char ch, char st_top) {
    switch (s) {
        case q0:
            if (ch == '0' && st_top == 'e') {
                push('X');
                return q0;
            } else if (ch == '0' && st_top == 'X') {
                push('X');
                return q0;
            } else if (ch == '1' && st_top == 'X') {
                pop();
                return q1;
            }
            break;
        case q1:
            if (ch == '1' && st_top == 'X') {
                pop();
                return q1;
            }
            break;
    }
    return q2;
}

int main() {
    st.top = -1;
    char input[20];
    enum state curr_state = q0;
    printf("Enter a binary string: ");
    scanf("%s", input);

    push('e');  // Initial stack symbol
    int i = 0;
    while (input[i] != '\0') {
        char st_top = get_stack_top();
        curr_state = delta(curr_state, input[i], st_top);
        i++;
    }

    if (curr_state == q1 && get_stack_top() == 'e') {
        printf("The string %s is accepted\n", input);
    } else {
        printf("The string %s is rejected\n", input);
    }

    return 0;
}
