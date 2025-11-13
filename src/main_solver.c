#include <stdio.h>
#include <string.h>
#include "solver.h"
#include "wordlist.h"
#include "game.h"

int main() {

    WordList wl = load_wordlist("dict/words.txt");

    if (wl.size == 0) {
        printf("Dictionary is empty!\n");
        return 0;
    }

    const char *target = pick_random_word(wl);
    printf("=== WORDLE SOLVER ===\n");
    printf("Target word (hidden from solver) = %s\n\n", target);

    Solver solver = solver_init(wl);
    int feedback[WORD_LENGTH];

    for (int attempt = 1; attempt <= 6; attempt++) {

        char *guess = solver_next_guess(solver);

        if (!guess) {
            printf("Solver has no words left! Failed.\n");
            break;
        }

        printf("Attempt %d: %s\n", attempt, guess);

        compute_feedback(guess, target, feedback);
        print_feedback(guess, feedback);

        if (check_win(guess, target)) {
            printf("\n🎉 SOLVER FOUND THE WORD '%s' IN %d ATTEMPTS!\n", target, attempt);
            solver_free(solver);
            free_wordlist(wl);
            printf("Press ENTER to exit...");
            getchar(); getchar();
            return 0;
        }

        solver_filter(&solver, guess, feedback);
    }

    printf("\n❌ SOLVER FAILED! The word was: %s\n", target);

    solver_free(solver);
    free_wordlist(wl);

    printf("Press ENTER to exit...");
    getchar(); getchar();
    return 0;
}
