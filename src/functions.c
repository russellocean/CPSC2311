/*************************
 *Russell Welch
 *CPSC 2311 001
 *rowelch@clemson.edu
 *************************/

#include "functions.h"

void numSentences(FILE* in, FILE* out)
{
    // Assert that the file pointers are not NULL
    assert(in != NULL);
    assert(out != NULL);

    int ch, sentences = 0;

    // Read characters from the input file until EOF
    while ((ch = fgetc(in)) != EOF)
    {
        // If the character is a sentence-ending character
        if (ch == '.' || ch == '?' || ch == '!')
        {
            // Increment the sentence count
            sentences++;

            // Skip over any additional consecutive sentence-ending characters
            while ((ch = fgetc(in)) != EOF && (ch == '.' || ch == '?' || ch == '!'));
        }
    }

    // Print the total number of sentences to the output file
    fprintf(out, "Total number of sentences: %d\n", sentences);

    // Reset the file pointer to the beginning of the input file
    fseek(in, 0, SEEK_SET);
}

void numWords(FILE* in, FILE* out)
{
    // Assert that the file pointers are not NULL
    assert(in != NULL);
    assert(out != NULL);

    int ch, words = 0, inWord = 0;

    // Read characters from the input file until EOF
    while ((ch = fgetc(in)) != EOF)
    {
        // If the character is a space
        if (isspace(ch))
        {
            // If we're currently in a word
            if (inWord)
            {
                // Increment the word count and exit the word
                words++;
                inWord = 0;
            }
        }
        else
        {
            // If the character is not a space, we're in a word
            inWord = 1;
        }
    }

    // If the file ended in the middle of a word, count that word
    if (inWord)
    {
        words++;
    }

    // Print the total number of words to the output file
    fprintf(out, "Total number of words: %d\n", words);

    // Reset the file pointer to the beginning of the input file
    fseek(in, 0, SEEK_SET);
}