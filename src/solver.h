#ifndef SOLVER_H
#define SOLVER_H

#include "wordlist.h"
#include "game.h"

typedef struct {
    char **candidates;   
    size_t size;       
} Solver;

Solver solver_init(WordList wl);

void solver_free(Solver s);

char* solver_next_guess(Solver s);

void solver_filter(Solver *s, const char *guess, int feedback[WORD_LENGTH]);

#endif
