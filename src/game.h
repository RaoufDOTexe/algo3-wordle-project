#ifndef GAME_H
#define GAME_H

#define WORD_LENGTH 5

// Feedback codes
#define GRAY   0
#define YELLOW 1
#define GREEN  2

// Validate guess (must be 5 letters)
int validate_guess(const char *guess);

// Compute feedback: fills array feedback[5]
void compute_feedback(const char *guess, const char *target, int feedback[WORD_LENGTH]);

// Print feedback nicely (ex: G Y . . G)
void print_feedback(const char *guess, int feedback[WORD_LENGTH]);

// Check if guess == target
int check_win(const char *guess, const char *target);

#endif
