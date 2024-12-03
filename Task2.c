#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define HASH_SIZE 100

typedef struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
    struct WordCount *next;
} WordCount;

unsigned int hash(const char *word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue = (hashValue * 31) + tolower(*word);
        word++;
    }
    return hashValue % HASH_SIZE;
}

void insertWord(WordCount *table[], const char *word) {
    unsigned int index = hash(word);
    WordCount *entry = table[index];

    while (entry != NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    WordCount *newEntry = (WordCount *)malloc(sizeof(WordCount));
    strcpy(newEntry->word, word);
    newEntry->count = 1;
    newEntry->next = table[index];
    table[index] = newEntry;
}

void processFile(const char *filename, WordCount *table[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%99s", word) == 1) {
        int i = 0;
        while (word[i]) {
            word[i] = tolower(word[i]);
            if (!isalnum(word[i])) {
                word[i] = '\0';
                break;
            }
            i++;
        }
        if (strlen(word) > 0) insertWord(table, word);
    }

    fclose(file);
}

void printWordCounts(WordCount *table[]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *entry = table[i];
        while (entry != NULL) {
            printf("%s: %d\n", entry->word, entry->count);
            entry = entry->next;
        }
    }
}

int main() {
    WordCount *table[HASH_SIZE] = { NULL };
    processFile("textfile.txt", table);
    printWordCounts(table);
    return 0;
}
