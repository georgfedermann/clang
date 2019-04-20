#include <stdio.h>

#define MAX_LINE_LENGTH 1000

// use variables external to all functions as opposed to automatic variables
// -> external variables
int maxLengthSeenSoFar;
char currentLine[MAX_LINE_LENGTH];
char longestLine[MAX_LINE_LENGTH];

int getline1(void);
void copy(void);

int main(void) {
  int len;
  extern int maxLengthSeenSoFar;
  extern char longestLine[];

  maxLengthSeenSoFar = 0;
  while ((len = getline1()) > 0) {
    if (len > maxLengthSeenSoFar) {
      maxLengthSeenSoFar = len;
      copy();
    }
  }
  if (maxLengthSeenSoFar > 0) {
    printf("%s", longestLine);
  }
  return 0;
}

// getline1, externalized version
int getline1(void) {
  int c, i;
  extern char currentLine[];

  for (i = 0; i < MAX_LINE_LENGTH && (c = getchar()) != EOF && c != '\n'; i++) {
    currentLine[i] = c;
  }
  if (c == '\n') {
    currentLine[i] = c;
    ++i;
  }
  currentLine[i] = '\0';
  return i;
}

void copy(void) {
  int i;

  extern char currentLine[], longestLine[];

  for (i = 0; (longestLine[i] = currentLine[i]) != '\0'; i++)
    ;
}
