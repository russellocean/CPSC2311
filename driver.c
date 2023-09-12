/*************************
 *Russell Welch
 *CPSC 2311 001
 *rowelch@clemson.edu
 *************************/

#include "src/functions.h"
#include <assert.h>

int main(int argc, char* argv[])
{
    assert(argc == 3);

    FILE* in = fopen(argv[1], "r");
    assert(in != NULL);

    FILE* out = fopen(argv[2], "w");
    assert(out != NULL);

    numSentences(in, out);
    numWords(in, out);

    fclose(in);
    fclose(out);

    return 0;
}