#include <stdio.h>
#include <string.h>
// count characters in input
int main(void) {
  long characterCount = 0;
  long lineCount = 0;
  long wordCount = 0;
  int character;

  while ((character = getchar()) != EOF) {
    characterCount++;
    if (character == ' ') {
      wordCount++;
    } else if (((char)character) == '\n') {
      wordCount++;
      lineCount++;
    }
  }

  printf("%ld\t%ld\t%ld\n", lineCount, wordCount, characterCount);
  return 0;
}
