#include "wordlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

static void to_lowercase(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower((unsigned char)s[i]);
}

static void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

WordList load_wordlist(const char *filename) {
    WordList wl;
    wl.words = NULL;
    wl.size = 0;

    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Erreur d'ouverture de %s\n", filename);
        return wl;
    }

    size_t cap = 256;
    wl.words = malloc(cap * sizeof(char *));
    char buffer[128];

    while (fgets(buffer, sizeof(buffer), f)) {
        trim_newline(buffer);
        to_lowercase(buffer);

        if (strlen(buffer) != WORD_LENGTH)
            continue;

        int ok = 1;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (!isalpha(buffer[i])) { ok = 0; break; }
        }
        if (!ok) continue;

        if (wl.size >= cap) {
            cap *= 2;
            wl.words = realloc(wl.words, cap * sizeof(char *));
        }

        wl.words[wl.size] = malloc(WORD_LENGTH + 1);
        strcpy(wl.words[wl.size], buffer);
        wl.size++;
    }

    fclose(f);
    srand(time(NULL));
    return wl;
}

void free_wordlist(WordList wl) {
    for (size_t i = 0; i < wl.size; i++)
        free(wl.words[i]);
    free(wl.words);
}

int is_in_dictionary(WordList wl, const char *word) {
    for (size_t i = 0; i < wl.size; i++)
        if (strcmp(wl.words[i], word) == 0)
            return 1;
    return 0;
}

char *pick_random_word(WordList wl) {
    if (wl.size == 0) return NULL;
    int idx = rand() % wl.size;
    return wl.words[idx];
}
