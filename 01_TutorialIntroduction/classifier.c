#include <stdio.h>

// counts the number of occurrences for each digit, whitespace and character
// data

int main(void) {
  int character;
  long whitespaceCount = 0, characterCount = 0;
  int ndigit[10];

  // initialize array elements to 0
  int c;
  for (c = 0; c < 10; c++) {
    ndigit[c] = 0;
  }

  while ((character = getchar()) != EOF) {
    if (character >= '0' && character <= '9') {
      ++ndigit[character - '0'];
    } else if (character == ' ' || character == '\t' || character == '\n') {
      ++whitespaceCount;
    } else {
      ++characterCount;
    }
  }
  printf("digits = ");
  int i;
  for (i = 0; i < 10; i++) {
    printf(" %d", ndigit[i]);
  }
  printf(", white space = %ld, character count = %ld.\n", whitespaceCount,
         characterCount);
  return 0;
}
