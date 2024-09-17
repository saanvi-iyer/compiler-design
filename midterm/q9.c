//shift reduce parser

#include <stdio.h>
#include <string.h>

#define STACK_SIZE 100
#define INPUT_SIZE 100

char stack[STACK_SIZE];
char input[INPUT_SIZE];
int top = -1;  // Stack pointer

// Push to the stack
void push(char c) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop from the stack
void pop(int n) {
    if (top >= n - 1) {
        top -= n;
    } else {
        printf("Stack underflow\n");
    }
}

// Display the current stack and input
void display() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\nInput: %s\n", input);
}

// Function to check for reductions
void reduce() {
    while (1) {
        // Try reducing "ab" to "S"
        if (top >= 1 && stack[top-1] == 'a' && stack[top] == 'b') {
            printf("Reducing 'ab' to 'S'\n");
            pop(2);  // Pop 'a' and 'b'
            push('S');  // Push 'S'
            display();
        }
        // Try reducing "aSb" to "S"
        else if (top >= 2 && stack[top-2] == 'a' && stack[top-1] == 'S' && stack[top] == 'b') {
            printf("Reducing 'aSb' to 'S'\n");
            pop(3);  // Pop 'a', 'S', and 'b'
            push('S');  // Push 'S'
            display();
        } else {
            break;  // No more reductions possible
        }
    }
}

// Shift-Reduce Parser function
void shiftReduceParser() {
    printf("Starting Shift-Reduce Parsing...\n");
    
    while (strlen(input) > 0) {
        // Shift: move first symbol of input to stack
        printf("Shifting '%c'\n", input[0]);
        push(input[0]);
        // Remove the first character from input
        memmove(input, input + 1, strlen(input));

        display();

        // Try to reduce after each shift
        reduce();
    }

    // Check if the final stack contains only the start symbol 'S'
    if (top == 0 && stack[top] == 'S') {
        printf("Input accepted: Successfully parsed.\n");
    } else {
        printf("Input rejected: Parsing failed.\n");
    }
}

int main() {
    // Initialize the input string
    printf("Enter the input string (e.g., 'aabb'): ");
    scanf("%s", input);

    // Call the shift-reduce parser
    shiftReduceParser();

    return 0;
}
