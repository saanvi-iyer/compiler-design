#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

// Global variables for storing the first and follow sets
char productions[MAX][MAX], firsts[MAX][MAX], follows[MAX][MAX];
int n;  // Number of productions

void addToSet(char set[], char val) {
    int i;
    for (i = 0; set[i] != '\0'; i++) {
        if (set[i] == val) return;
    }
    set[i] = val;
    set[i + 1] = '\0';
}

void findFirst(char symbol, int prodIndex) {
    int i, j;

    // If it's a terminal, add it to the First set
    if (!isupper(symbol)) {
        addToSet(firsts[prodIndex], symbol);
        return;
    }

    // Otherwise, look for production rules for this symbol
    for (i = 0; i < n; i++) {
        if (productions[i][0] == symbol) {
            if (productions[i][2] == '#') {  // Epsilon production
                addToSet(firsts[prodIndex], '#');
            } else {
                findFirst(productions[i][2], prodIndex);
            }
        }
    }
}

void findFollow(char symbol) {
    int i, j, k;

    // Add '$' to the Follow set of the start symbol
    if (symbol == productions[0][0]) {
        addToSet(follows[0], '$');
    }

    // Look for occurrences of the symbol in productions
    for (i = 0; i < n; i++) {
        for (j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1] != '\0') {
                    if (!isupper(productions[i][j + 1])) {
                        addToSet(follows[symbol - 'A'], productions[i][j + 1]);
                    } else {
                        for (k = 0; firsts[productions[i][j + 1] - 'A'][k] != '\0'; k++) {
                            if (firsts[productions[i][j + 1] - 'A'][k] != '#') {
                                addToSet(follows[symbol - 'A'], firsts[productions[i][j + 1] - 'A'][k]);
                            }
                        }

                        if (strchr(firsts[productions[i][j + 1] - 'A'], '#')) {
                            findFollow(productions[i][0]);
                            for (k = 0; follows[productions[i][0] - 'A'][k] != '\0'; k++) {
                                addToSet(follows[symbol - 'A'], follows[productions[i][0] - 'A'][k]);
                            }
                        }
                    }
                } else {
                    findFollow(productions[i][0]);
                    for (k = 0; follows[productions[i][0] - 'A'][k] != '\0'; k++) {
                        addToSet(follows[symbol - 'A'], follows[productions[i][0] - 'A'][k]);
                    }
                }
            }
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (e.g., A=Bc):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    // Initialize the First and Follow sets
    for (i = 0; i < n; i++) {
        firsts[i][0] = '\0';
        follows[i][0] = '\0';
    }

    // Calculate First sets
    for (i = 0; i < n; i++) {
        findFirst(productions[i][0], productions[i][0] - 'A');
    }

    // Calculate Follow sets
    for (i = 0; i < n; i++) {
        findFollow(productions[i][0]);
    }

    // Print First sets
    printf("\nFirst sets:\n");
    for (i = 0; i < n; i++) {
        printf("First(%c) = { ", productions[i][0]);
        for (j = 0; firsts[i][j] != '\0'; j++) {
            printf("%c ", firsts[i][j]);
        }
        printf("}\n");
    }

    // Print Follow sets
    printf("\nFollow sets:\n");
    for (i = 0; i < n; i++) {
        printf("Follow(%c) = { ", productions[i][0]);
        for (j = 0; follows[i][j] != '\0'; j++) {
            printf("%c ", follows[i][j]);
        }
        printf("}\n");
    }

    return 0;
}
