#include "game.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate_guess(const char *guess) {
    if (strlen(guess) != WORD_LENGTH)
        return 0;

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (!isalpha(guess[i]))
            return 0;
    }

    return 1;
}

void compute_feedback(const char *guess, const char *target, int feedback[WORD_LENGTH]) {
    // Step 1: init
    for (int i = 0; i < WORD_LENGTH; i++)
        feedback[i] = GRAY;

    // Step 2: GREEN positions first
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == target[i]) {
            feedback[i] = GREEN;
        }
    }

    // Step 3: YELLOW positions
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (feedback[i] == GREEN)
            continue;

        for (int j = 0; j < WORD_LENGTH; j++) {
            if (i != j && guess[i] == target[j] && feedback[i] == GRAY) {
                feedback[i] = YELLOW;
                break;
            }
        }
    }
}

void print_feedback(const char *guess, int feedback[WORD_LENGTH]) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        char c = guess[i];
        int f = feedback[i];

        if (f == GREEN)
            printf("\033[42m %c \033[0m ", c);  
        else if (f == YELLOW)
            printf("\033[43m %c \033[0m ", c);
        else
            printf("\033[100m %c \033[0m ", c);
    }
    printf("\n");
}


int check_win(const char *guess, const char *target) {
    return strcmp(guess, target) == 0;
}
