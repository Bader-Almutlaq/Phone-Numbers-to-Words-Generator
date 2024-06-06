#include "header.h"

int main()
{
    /* Input for phone number */
    char phoneNumber[8];
    printf("Enter a seven-digit phone number (avoiding 0 and 1): ");
    scanf("%7s", phoneNumber);

    /* Validation for correct input */
    if (strlen(phoneNumber) != 7)
    {
        printf("Please enter a valid seven-digit phone number.\n");
        return 1;
    }

    /* Checking for 0 or 1 in the phone number */
    int i;
    for (i = 0; i < 7; i++)
    {
        if (phoneNumber[i] == '0' || phoneNumber[i] == '1')
        {
            printf("Please enter a valid seven-digit phone number without 0 or 1.\n");
            return 1;
        }
    }

    /* Buffer to store the generated word */
    char word[8];
    word[7] = '\0';

    char generated[MAX_POSSIBLE_COMBINATIONS + 1][MAX_WORD_SIZE]; /* The maximum combinations count is 3^7 = 2187*/
    int generatedWordsCount = 0;

    /* Generate all possible words from the phone number */
    generateWords(generated, phoneNumber, word, 0, &generatedWordsCount);
    printf("\nAll possible words have been generated.\n");

    /* Opining the dictionary and the output file */
    FILE *dictionaryFile, *outputFile;

    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL)
    {
        perror("Error opening file2.txt");
        return 1;
    }

    int countDictionaryWords = 0;
    char **dictionary = readDictionary(dictionaryFile, &countDictionaryWords); /* Reading the dictionary into a buffer */

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        perror("Error opening output.txt");
        fclose(dictionaryFile);
        return 1;
    }

    /* Searching for the generated words in the dictionary buffer and writing them in the output file */
    searchInDictionary(generated, dictionary, outputFile, generatedWordsCount, countDictionaryWords);

    /* Closing opened files */
    fclose(dictionaryFile);
    fclose(outputFile);

    /* freeing the allocated memory for the dictionary */
    free(dictionary);
    printf("Words have been written to 'output.txt'.\n\n");

    return 0;
}
