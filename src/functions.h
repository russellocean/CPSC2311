/*************************
 *Russell Welch
 *CPSC 2311 001
 *rowelch@clemson.edu
 *************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

/* 
 * Function: numSentences
 * ----------------------------
 *   Counts the number of sentences in a file.
 *
 *   in: FILE pointer to the input file
 *   out: FILE pointer to the output file
 *
 *   Returns: void
 *
 *   This function reads the data from the input file, counting the number of sentences.
 *   A sentence is assumed to end with either a '.', '?', or '!' character. 
 *   Multiple consecutive sentence-ending characters are treated as a single sentence end.
 */
void numSentences(FILE* in, FILE* out);

/* 
 * Function: numWords
 * ----------------------------
 *   Counts the number of words in a file.
 *
 *   in: FILE pointer to the input file
 *   out: FILE pointer to the output file
 *
 *   Returns: void
 *
 *   This function reads the data from the input file, counting the number of words.
 *   A word is assumed to be a sequence of characters separated by spaces.
 *   Multiple consecutive spaces are treated as a single word separator.
 */
void numWords(FILE* in, FILE* out);

#endif // FUNCTIONS_H