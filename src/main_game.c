#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wordlist.h"
#include "game.h"

int main() {

    // Load dictionary
    WordList wl = load_wordlist("dict/words.txt");

    if (wl.size == 0) {
        printf("Dictionary is empty! Add some 5-letter words.\n");
        printf("Press ENTER to exit...");
        getchar();
        return 0;
    }

    printf("Loaded %zu words.\n", wl.size);

    // Pick target
    const char *target = pick_random_word(wl);
    // (remove comment for debugging)
    // printf("DEBUG | target = %s\n", target);

    printf("\n=== WORDLE GAME ===\n");
    printf("You have 6 attempts to guess the 5-letter word.\n\n");

    int feedback[WORD_LENGTH];
    char guess[100];   // buffer for input

    for (int attempt = 1; attempt <= 6; attempt++) {

        printf("Attempt %d/6: ", attempt);
        scanf("%s", guess);

        // convert guess to lowercase
        for (int i = 0; guess[i]; i++)
            guess[i] = tolower(guess[i]);

        // validate structure
        if (!validate_guess(guess)) {
            printf("Invalid guess! Must be 5 letters.\n");
            attempt--;   // do not count this try
            continue;
        }

        // check if guess exists in dictionary
        if (!is_in_dictionary(wl, guess)) {
            printf("Word not found in dictionary!\n");
            attempt--;   // do not count
            continue;
        }

        // compute feedback
        compute_feedback(guess, target, feedback);

        // print result
        print_feedback(guess, feedback);

        // check win condition
        if (check_win(guess, target)) {
            printf("\n🎉 Congratulations! You found the word '%s'!\n", target);
            printf("Press ENTER to exit...");
            getchar(); getchar();
            free_wordlist(wl);
            return 0;
        }
    }

    // lost
    printf("\n❌ You failed! The word was: %s\n", target);
    printf("Press ENTER to exit...");
    getchar(); getchar();

    free_wordlist(wl);
    return 0;
}
