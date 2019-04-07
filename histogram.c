#include <stdio.h>
// program reads text from std in and keeps track of the number of words as
// well as the number of letters per word.

// define constants for the states of the word parser
#define WITHIN_WORD_BOUNDARIES 0
#define OUTSIDE_WORD_BOUNDARIES 1

int main(void) {
  // initialize objects
  int wordCount=0;
  int parserState = OUTSIDE_WORD_BOUNDARIES;
  // expect word lengths from 1 to 20. Create array that will hold word lengths
  // where the index is the number of letters and the value is the found number
  // of words in the input text for each number of letters.
  int wordStats[20];
  // initialize wordStats array to all zeros
  int c;
  for(c = 0; c < 20; c++){
    wordStats[c] = 0;
    printf("Element at position %d is %d\n", c, wordStats[c]);
  }

  printf("wordCount is %d and parserState is %d.\n", wordCount, parserState);

  return 0;
}
