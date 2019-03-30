#include <stdio.h>
#include <string.h>
// count characters in input
// use states to define whether current position is within or out
// of the boundaries of a word. If out of boundaries the next non-
// whitespace character would mark the beginning of the next word.
#define WITHIN_WORD_BOUNDARIES 0
#define OUTSIDE_WORD_BOUNDARIES 1
int main(void) {
  long characterCount = 0;
  long lineCount = 0;
  long wordCount = 0;
  int character;
  int parserState = OUTSIDE_WORD_BOUNDARIES;

  while ((character = getchar()) != EOF) {
    characterCount++;
    if (((char)character) == '\n') {
      lineCount++;
    }
    if (character == ' ' || character == '\n' || character == '\t') {
      parserState = OUTSIDE_WORD_BOUNDARIES;
    } else if (parserState == OUTSIDE_WORD_BOUNDARIES) {
      wordCount++;
      parserState = WITHIN_WORD_BOUNDARIES;
    }
  }

  printf("%ld\t%ld\t%ld\n", lineCount, wordCount, characterCount);
  return 0;
}
