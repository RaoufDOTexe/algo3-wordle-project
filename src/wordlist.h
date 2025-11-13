#ifndef WORDLIST_H
#define WORDLIST_H

#include <stddef.h>

#define WORD_LENGTH 5

typedef struct {
    char **words;   
    size_t size;    
} WordList;

WordList load_wordlist(const char *filename);
void free_wordlist(WordList wl);
int is_in_dictionary(WordList wl, const char *word);
char *pick_random_word(WordList wl);

#endif
