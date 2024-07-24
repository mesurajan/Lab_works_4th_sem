//wap to implement generic DFA which can simulate the any DFAdefined by user.

#include <stdio.h>

#define MAX_STATES 100
#define MAX_ALPHABET 10

int main() {
    int num_states, num_alphabet, num_accepting_states;
    int initial_state, accepting_states[MAX_STATES];
    int transition[MAX_STATES][MAX_ALPHABET];
    char alphabet[MAX_ALPHABET], input[100];
    int curr_state;

    // Function to check if a state is accepting
    int is_accepting_state(int s, int num_accepting_states, int accepting_states[]) {
        for (int i = 0; i < num_accepting_states; i++) {
            if (accepting_states[i] == s) {
                return 1;
            }
        }
        return 0;
    }

    // Function to get the index of the alphabet symbol
    int get_alphabet_index(char symbol, int num_alphabet, char alphabet[]) {
        for (int i = 0; i < num_alphabet; i++) {
            if (alphabet[i] == symbol) {
                return i;
            }
        }
        return -1; // Invalid symbol
    }

    // Read the number of states
    printf("Enter the number of states (max %d): ", MAX_STATES);
    scanf("%d", &num_states);
    if (num_states <= 0 || num_states > MAX_STATES) {
        printf("Error: Number of states must be between 1 and %d.\n", MAX_STATES);
        return 1;
    }

    // Read the number of alphabet symbols
    printf("Enter the number of alphabet symbols (max %d): ", MAX_ALPHABET);
    scanf("%d", &num_alphabet);
    if (num_alphabet <= 0 || num_alphabet > MAX_ALPHABET) {
        printf("Error: Number of alphabet symbols must be between 1 and %d.\n", MAX_ALPHABET);
        return 1;
    }

    // Read the alphabet symbols
    printf("Enter the alphabet symbols: ");
    for (int i = 0; i < num_alphabet; i++) {
        scanf(" %c", &alphabet[i]);
    }

    // Read the transition table
    printf("Enter the transition table (use state numbers starting from 0):\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_alphabet; j++) {
            printf("δ(q%d, %c) = q", i, alphabet[j]);
            scanf("%d", &transition[i][j]);
            if (transition[i][j] < 0 || transition[i][j] >= num_states) {
                printf("Error: Transition state must be between 0 and %d.\n", num_states - 1);
                return 1;
            }
        }
    }

    // Read the initial state
    printf("Enter the initial state: q");
    scanf("%d", &initial_state);
    if (initial_state < 0 || initial_state >= num_states) {
        printf("Error: Initial state must be between 0 and %d.\n", num_states - 1);
        return 1;
    }

    // Read the number of accepting states
    printf("Enter the number of accepting states: ");
    scanf("%d", &num_accepting_states);
    if (num_accepting_states < 0 || num_accepting_states > num_states) {
        printf("Error: Number of accepting states must be between 0 and %d.\n", num_states);
        return 1;
    }

    // Read the accepting states
    printf("Enter the accepting states: ");
    for (int i = 0; i < num_accepting_states; i++) {
        scanf("%d", &accepting_states[i]);
        if (accepting_states[i] < 0 || accepting_states[i] >= num_states) {
            printf("Error: Accepting state must be between 0 and %d.\n", num_states - 1);
            return 1;
        }
    }

    // Read the input string to simulate
    printf("Enter a string to simulate (max 99 characters): ");
    scanf("%s", input);
    
    // Simulate the DFA
    curr_state = initial_state;

    for (int i = 0; input[i] != '\0'; i++) {
        int symbol_index = get_alphabet_index(input[i], num_alphabet, alphabet);
        if (symbol_index == -1) {
            printf("Invalid symbol %c in input\n", input[i]);
            return 1;
        }
        curr_state = transition[curr_state][symbol_index];
    }

    // Check if the final state is accepting
    if (is_accepting_state(curr_state, num_accepting_states, accepting_states)) {
        printf("Provided string is Accepted\n");
    } else {
        printf("Provided string is Rejected\n");
    }

    return 0;
}
