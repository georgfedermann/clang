#include <stdio.h>
// program reads text from std in and keeps track of the number of words as
// well as the number of letters per word.

// define constants for the states of the word parser
#define WITHIN_WORD_BOUNDARIES 0
#define OUTSIDE_WORD_BOUNDARIES 1
#define MAX_WORD_LENGTH 25
#define HISTOGRAM_HORIZONTAL_WIDTH 80
#define HISTOGRAM_VERTICAL_HEIGHT 20

int isWhitespace(int character) {
  // is whitespace if is not a number
  return (character < 0x30 || character > 0x39) &&
         // and not an upper case letter
         (character < 0x41 || character > 0x5A) &&
         // and not a lower case letter
         (character < 0x61 || character > 0x7A);
}

int main(void) {
  // initialize objects
  int parserState = OUTSIDE_WORD_BOUNDARIES;
  // expect word lengths from 1 to MAX_WORD_LENGTH.
  // Create array that will hold word lengths
  // where the index is the number of letters and the value is the found number
  // of words in the input text for each number of letters.
  int wordStats[MAX_WORD_LENGTH];
  // this array will be filled with the percentual amounts of words found for
  // wordlength==arrayIndex to total number of words found.
  int barHeight[MAX_WORD_LENGTH];
  // count characters within the current word
  int currentWordLength = 0;
  char currentWord[MAX_WORD_LENGTH];

  // initialize wordStats array to all zeros
  int c;
  for (c = 0; c < MAX_WORD_LENGTH; c++) {
    wordStats[c] = 0;
    currentWord[c] = ' ';
    barHeight[c] = 0;
  }

  // analyze input and create histogram
  int character;
  while ((character = getchar()) != EOF) {
    if (isWhitespace(character) && parserState == WITHIN_WORD_BOUNDARIES) {
      wordStats[currentWordLength]++;
      parserState = OUTSIDE_WORD_BOUNDARIES;
      if (currentWordLength >= 16) {
        printf("Found long word: %s.\n", &currentWord[0]);
      }
      for (c = 0; c < MAX_WORD_LENGTH; c++) {
        currentWord[c] = ' ';
      }
    } else if (!isWhitespace(character) &&
               parserState == WITHIN_WORD_BOUNDARIES) {
      currentWordLength++;
      currentWord[currentWordLength - 1] = character;
    } else if (!isWhitespace(character) &&
               parserState == OUTSIDE_WORD_BOUNDARIES) {
      parserState = WITHIN_WORD_BOUNDARIES;
      currentWordLength = 1;
      currentWord[currentWordLength - 1] = character;
    } else {
      // ignore cases
      // !isWhitespace() && parserState == OUTSIDE_WORD_BOUNDARIES
    }
  }

  // now print the histogramm
  // TODO move logic to functions later
  // common logic
  int totalNumberOfWords = 0;
  for (c = 1; c < MAX_WORD_LENGTH; c++) {
    totalNumberOfWords += wordStats[c];
  }
  for (c = 1; c < MAX_WORD_LENGTH; c++) {
    printf("Number of words with %d characters is %d.\n", c, wordStats[c]);
    barHeight[c] =
        ((float)HISTOGRAM_HORIZONTAL_WIDTH) / totalNumberOfWords * wordStats[c];
  }

  printf("Total number of words: %d.\n", totalNumberOfWords);

  // output horizontal version (easier)
  puts("\nHorizontal histogram:");
  int row = 0, col = 0;
  for (row = 1; row < MAX_WORD_LENGTH; row++) {
    printf("%2d->%5d\t", row, wordStats[row]);
    for (col = 0; col < barHeight[row]; col++) {
      printf("*");
    }
    printf("\n");
  }

  // vertical version (slightly more difficult)
  puts("\nVertical histogram:");
  for (row = MAX_WORD_LENGTH - 1; row > 0; row--) {
    for (col = 1; col < MAX_WORD_LENGTH; col++) {
      if (barHeight[col] >= row) {
        printf("*");
      } else if (row == 1) {
        printf("_");
      } else {
        printf(" ");
      }
    }
    puts("");
  }
  return 0;
}
