#include <stdio.h>
// finds the longest line in stdin and prints it

#define MAX_LINE_LENGTH 10000

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

// while (there's another line)
//   if (the current line is longer than the previously longest)
//     save it
//     save its length
// print longest line

int main() {
  int len;                        // current line length
  int max;                        // maximum length seen so far
  char line[MAX_LINE_LENGTH];     // current input line
  char longest[MAX_LINE_LENGTH];  // longest line seen so far

  max = 0;
  while ((len = getline1(line, MAX_LINE_LENGTH)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    // at some point a longest line was found
    printf("%s", longest);
  }
  return 0;
}

// reads a line of text from the currently open file, returns length of line
int getline1(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
