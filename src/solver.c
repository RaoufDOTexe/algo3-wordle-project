#include "solver.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Solver solver_init(WordList wl) {
    Solver s;
    s.size = wl.size;
    s.candidates = malloc(s.size * sizeof(char*));

    for (size_t i = 0; i < s.size; i++) {
        s.candidates[i] = malloc(WORD_LENGTH + 1);
        strcpy(s.candidates[i], wl.words[i]);
    }
    return s;
}

void solver_free(Solver s) {
    for (size_t i = 0; i < s.size; i++)
        free(s.candidates[i]);
    free(s.candidates);
}

char* solver_next_guess(Solver s) {
    if (s.size == 0) return NULL;
    return s.candidates[0];
}

static int matches_feedback(const char *word, const char *guess, int fb[WORD_LENGTH]) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (fb[i] == GREEN) {
            if (word[i] != guess[i]) return 0;
        }
        else if (fb[i] == YELLOW) {
            if (word[i] == guess[i]) return 0;

            int exists = 0;
            for (int j = 0; j < WORD_LENGTH; j++)
                if (word[j] == guess[i]) exists = 1;

            if (!exists) return 0;
        }
        else if (fb[i] == GRAY) {
            int exists = 0;
            for (int j = 0; j < WORD_LENGTH; j++)
                if (word[j] == guess[i]) exists = 1;

            if (exists) return 0;
        }
    }
    return 1;
}

void solver_filter(Solver *s, const char *guess, int fb[WORD_LENGTH]) {

    char **newlist = malloc(s->size * sizeof(char*));
    size_t newsize = 0;

    for (size_t i = 0; i < s->size; i++) {
        if (matches_feedback(s->candidates[i], guess, fb)) {
            newlist[newsize] = s->candidates[i];
            newsize++;
        } else {
            free(s->candidates[i]);
        }
    }

    free(s->candidates);
    s->candidates = newlist;
    s->size = newsize;
}
