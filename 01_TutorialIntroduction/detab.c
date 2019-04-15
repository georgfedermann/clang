#include <stdio.h>
// scans a character stream that replaces tab characters in the input stream by
// the propert number of blanks.

// max line length in characters
#define MAX_LINE_LENGTH 120
#define BLANKS_IN_TAB 7
#define BLANK ' '

int readline(char currentLine[], int maxLineLength);

void replaceTabs(char currentLine[]);

// restores from to backup until '\0' is found or length is met
void backup(char from[], char backup[], int start, int length);

// restores from to target until '\0' is found
void restore(char from[], char target[], int targetStartIndex);

int main(void) {
  char currentLine[120];
  int maxLineLength = MAX_LINE_LENGTH, currentLineLength;

  while ((currentLineLength = readline(currentLine, maxLineLength)) > 0) {
    replaceTabs(currentLine);
    printf("%s", currentLine);
  }

  return 0;
}

int readline(char currentLine[], int maxLineLength) {
  int counter, character;
  for (counter = 0; counter < maxLineLength - 1 &&
                    ((character = getchar())) != EOF && character != '\n';
       counter++) {
    currentLine[counter] = character;
  }
  if (character == '\n') {
    currentLine[counter] = '\n';
    counter++;
  }
  currentLine[counter] = '\0';
  return counter;
}

// scans a string and replaces instances of tabs by a fitting amount of blanks.
// the end of the string is marked by \0.
void replaceTabs(char currentLine[]) {
  // i .. counter, c .. character
  // blankCount .. counter variable when printing blanks for replaced tabs
  // blankNumber .. holds the number of blanks required to replace a specific
  // tab.
  int i, c, blankCount, blankNumber;
  char backupArray[MAX_LINE_LENGTH];

  for (i = 0; (c = currentLine[i]) != '\0'; i++) {
    if (c == '\t') {
      backup(currentLine, backupArray, i + 1, MAX_LINE_LENGTH - 1 - i);
      // replaceTabs(backupArray);
      blankNumber = BLANKS_IN_TAB - (i % BLANKS_IN_TAB);
      for (blankCount = 0; blankCount < blankNumber; blankCount++) {
        currentLine[i++] = BLANK;
      }
      restore(backupArray, currentLine, i);
      i--;
    }
  }
}

void backup(char from[], char backup[], int start, int length) {
  // i .. counter, c .. character
  int i, c;
  for (i = start; i <= length && (c = from[i]) != '\0'; i++) {
    backup[i - start] = c;
  }
  backup[i - start] = '\0';
}

// restores from to target until '\0' is found
void restore(char from[], char target[], int targetStartIndex) {
  // i .. counter, c .. character
  int i;
  for (i = targetStartIndex; from[i - targetStartIndex] != '\0'; i++) {
    target[i] = from[i - targetStartIndex];
  }
  target[i] = '\0';
}
