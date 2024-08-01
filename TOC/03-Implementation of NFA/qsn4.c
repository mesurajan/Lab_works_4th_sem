//NFA OVER {0,1} THAT ACCEPTS STRING CONTAINING SUBSTRING 0110 OR 1001
// Implement NFA over alphabets {0,1} that accepts strings containing "0110" or "1001"
#include <stdio.h>
#include <string.h>

char input[20];
int l;
int flag;

// States for "0110" substring
void q3_0110(int i);
void q2_0110(int i);
void q1_0110(int i);
void q0_0110(int i);

// States for "1001" substring
void q3_1001(int i);
void q2_1001(int i);
void q1_1001(int i);
void q0_1001(int i);

void q3_0110(int i) {
    if (input[i] == '0') {
        flag = 1;
    }
}

void q2_0110(int i) {
    if (input[i] == '1') {
        q3_0110(i + 1);
    }
}

void q1_0110(int i) {
    if (input[i] == '1') {
        q2_0110(i + 1);
    }
}

void q0_0110(int i) {
    if (input[i] == '0') {
        q1_0110(i + 1);
    }
}

void q3_1001(int i) {
    if (input[i] == '1') {
        flag = 1;
    }
}

void q2_1001(int i) {
    if (input[i] == '0') {
        q3_1001(i + 1);
    }
}

void q1_1001(int i) {
    if (input[i] == '0') {
        q2_1001(i + 1);
    }
}

void q0_1001(int i) {
    if (input[i] == '1') {
        q1_1001(i + 1);
    }
}

void start(int i) {
    if (i < l) {
        q0_0110(i);
        q0_1001(i);
        if (flag == 0) {
            start(i + 1);
        }
    }
}

int main() {
    printf("Enter a binary string: ");
    scanf("%s", input);
    l = strlen(input);
    flag = 0;
    start(0);
    if (flag == 1) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is not accepted.\n");
    }
    return 0;
}
