//recursive descent parser
#include <stdio.h>
#include <ctype.h>

char input[100];
int i = 0, error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E() {
    // E → T E'
    printf("E → T E'\n");
    T();
    Eprime();
}

void Eprime() {
    // E' → + T E' | ε
    if (input[i] == '+') {
        i++;
        printf("E' → + T E'\n");
        T();
        Eprime();
    } else {
        // ε (empty production)
        printf("E' → ε\n");
    }
}

void T() {
    // T → F T'
    printf("T → F T'\n");
    F();
    Tprime();
}

void Tprime() {
    // T' → * F T' | ε
    if (input[i] == '*') {
        i++;
        printf("T' → * F T'\n");
        F();
        Tprime();
    } else {
        // ε (empty production)
        printf("T' → ε\n");
    }
}

void F() {
    // F → ( E ) | id
    if (input[i] == '(') {
        i++;
        printf("F → ( E )\n");
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    } else if (isalnum(input[i])) {
        printf("F → id\n");
        i++;
    } else {
        error = 1;
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    E();  // Start parsing with the start symbol E

    if (input[i] == '\0' && error == 0) {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }

    return 0;
}
