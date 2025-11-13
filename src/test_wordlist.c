#include <stdio.h>
#include "wordlist.h"

int main() {

    WordList wl = load_wordlist("dict/words.txt");

    printf("Loaded %zu words.\n", wl.size);

    if (wl.size > 0) {
        printf("Random word = %s\n", pick_random_word(wl));
    }

    printf("\nPress ENTER to exit...");
    getchar(); 
    getchar();

    free_wordlist(wl);
    return 0;
}
