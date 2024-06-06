#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_POSSIBLE_COMBINATIONS 2187 

void generateWords(char generated[][MAX_WORD_SIZE], char *phoneNumber, char *word, int index, int *count);
void searchInDictionary(char generated[][MAX_WORD_SIZE], char **dictionary, FILE *output, int countW, int countD);
char **readDictionary(FILE *file, int *wordCount);