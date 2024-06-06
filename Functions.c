#include "header.h"

/* Recursive function to generate all possible words from phone number */
void generateWords(char generated[][MAX_WORD_SIZE], char *phoneNumber, char *word, int index, int *count)
{
    /* Base case: If all digits processed, write the word to the buffer */
    if (index == 7)
    {
        word[index + 1] = '\0'; /* null terminating the word before copying */
        strcpy(generated[(*count)++], word);
        return;
    }

    /* Getting the current number to process it */
    char digit = phoneNumber[index];

    /* Corresponding letters for each digit */
    char letters[][4] = {
        "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

    /* If the digit is valid (2 to 9), explore all possible letters */
    if (digit >= '2' && digit <= '9')
    {
        /* Assigning the correct letters based on the number */
        char *letterOptions = letters[digit - '2'];
        int i;
        /* Iterating through letters to explore all combinations */
        for (i = 0; i < strlen(letterOptions); i++)
        {
            /* Assigning the corresponding letter to the correct index in the word */
            word[index] = letterOptions[i];

            /* Calling the function for the next number */
            generateWords(generated, phoneNumber, word, index + 1, count);
        }
    }
}

/* Function to search for the generated words in the dictionary buffer and write to the output file */
void searchInDictionary(char generatedWords[][MAX_WORD_SIZE], char **dictionary, FILE *outputFile, int countOfGeneratedWords, int countOfDictionaryWords)
{

    int currentWord = 0;
    /* Buffers to store the words that make a combination 2-5,3-4,4-3,5-2 */
    char first2[3];
    char last5[6];
    char first3[4];
    char last4[5];
    char first4[5];
    char last3[4];
    char first5[6];
    char last2[3];

    /* while the count of processed words is less than the total words we continue the search */
    while (currentWord < countOfGeneratedWords)
    {

        /* Storing the first 2 , 3, 4 and 5 characters to search for them */
        strncpy(first2, generatedWords[currentWord], 2);
        first2[2] = '\0';
        strncpy(first3, generatedWords[currentWord], 3);
        first3[3] = '\0';
        strncpy(first4, generatedWords[currentWord], 4);
        first4[4] = '\0';
        strncpy(first5, generatedWords[currentWord], 5);
        first5[5] = '\0';

        /* Storing the last 2 , 3, 4 and 5 characters to search for them */
        strncpy(last5, generatedWords[currentWord] + 2, 5);
        last5[5] = '\0';
        strncpy(last4, generatedWords[currentWord] + 3, 4);
        last4[4] = '\0';
        strncpy(last3, generatedWords[currentWord] + 4, 3);
        last3[3] = '\0';
        strncpy(last2, generatedWords[currentWord] + 5, 2);
        last2[2] = '\0';

        int currentDictionaryWord = 0;

        /* Flags to know which word was found */
        int foundAll = 0, foundFirst2 = 0, foundFirst3 = 0, foundFirst4 = 0, foundFirst5 = 0;
        int foundLast2 = 0, foundLast3 = 0, foundLast4 = 0, foundLast5 = 0;

        /* Search for the word in the dictionary while the processed words count is less than the total words in the dictionary */
        while (currentDictionaryWord < countOfDictionaryWords)
        {
            /* If match was found, write to the output file */
            if (strcmp(generatedWords[currentWord], dictionary[currentDictionaryWord]) == 0)
            {
                foundAll = 1;
                break; /* if we found the whole word in the dictionary we stop searching */
            }
            if (strcmp(first2, dictionary[currentDictionaryWord]) == 0) /* Checking if the first two letters form a word in the dictionary */
            {
                foundFirst2 = 1;
            }
            if (strcmp(first3, dictionary[currentDictionaryWord]) == 0) /* Checking if the first three letters form a word in the dictionary */
            {
                foundFirst3 = 1;
            }
            if (strcmp(first4, dictionary[currentDictionaryWord]) == 0) /* Checking if the first four letters form a word in the dictionary */
            {
                foundFirst4 = 1;
            }
            if (strcmp(first5, dictionary[currentDictionaryWord]) == 0) /* Checking if the first five letters form a word in the dictionary */
            {
                foundFirst5 = 1;
            }
            if (strcmp(last5, dictionary[currentDictionaryWord]) == 0) /* Checking if the last five letters form a word in the dictionary */
            {
                foundLast5 = 1;
            }
            if (strcmp(last4, dictionary[currentDictionaryWord]) == 0) /* Checking if the last four letters form a word in the dictionary */
            {
                foundLast4 = 1;
            }
            if (strcmp(last3, dictionary[currentDictionaryWord]) == 0) /* Checking if the last three letters form a word in the dictionary */
            {
                foundLast3 = 1;
            }
            if (strcmp(last2, dictionary[currentDictionaryWord]) == 0) /* Checking if the last two letters form a word in the dictionary */
            {
                foundLast2 = 1;
            }

            /* increment the counter to move to the next word */
            currentDictionaryWord++;

            /* if we found a combination of the word in the dictionary we stop searching */
            if (foundFirst2 && foundLast5)
                break;
            if (foundFirst3 && foundLast4)
                break;
            if (foundFirst4 && foundLast3)
                break;
            if (foundFirst5 && foundLast2)
                break;
        }

        /* Writing the word in the output file */
        if (foundAll)
        {
            fprintf(outputFile, "%s\n", generatedWords[currentWord]);
        }
        /* if the first 2 characters and the last 5 characters make a word in the dictionary write it in the file */
        if (foundFirst2 && foundLast5)
        {
            fprintf(outputFile, "%s", first2);
            fprintf(outputFile, "%s\n", last5);
        }
        /* if the first 3 characters and the last 4 characters make a word in the dictionary write it in the file */
        if (foundFirst3 && foundLast4)
        {
            fprintf(outputFile, "%s", first3);
            fprintf(outputFile, "%s\n", last4);
        }
        /* if the first 4 characters and the last 3 characters make a word in the dictionary write it in the file */
        if (foundFirst4 && foundLast3)
        {
            fprintf(outputFile, "%s", first4);
            fprintf(outputFile, "%s\n", last3);
        }
        /* if the first 5 characters and the last 2 characters make a word in the dictionary write it in the file */
        if (foundFirst5 && foundLast2)
        {
            fprintf(outputFile, "%s", first5);
            fprintf(outputFile, "%s\n", last2);
        }
        /* incrementing the counter to move to the next generated word */
        currentWord++;
    }
}

/* Function to read a dictionary store it in a buffer and return it and count the number of words */
char **readDictionary(FILE *file, int *wordCount)
{
    /* Initialize variables */
    char **words = NULL; /* Pointer to an array of strings (dictionary) */
    *wordCount = 0;      /* Initialize word count */

    /* Allocate memory for the initial string pointer */
    words = (char **)malloc(sizeof(char *));
    if (words == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    /* Buffer to store each word read from the file */
    char buffer[MAX_WORD_SIZE];

    /* Read words from the file until the end is reached */
    while (fscanf(file, "%s", buffer) == 1)
    {
        /* Allocate memory for the current word */
        words[*wordCount] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (words[*wordCount] == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        /* Copy the word from the buffer to the allocated memory */
        strcpy(words[*wordCount], buffer);

        /* Increment word count */
        (*wordCount)++;

        /* Resize the array to accommodate the new word */
        words = (char **)realloc(words, (*wordCount + 1) * sizeof(char *));
        if (words == NULL)
        {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    }

    /* Return the array of words */
    return words;
}
