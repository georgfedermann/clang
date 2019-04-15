#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

// demonstrate how to query data type limits from limits.h and float.h

void demonstrateCharOverflow(void) {
  char c = 0;
  int count = 0;
  do {
    count++;
    printf("%d -> %c.\n", c, c);
    c++;
  } while (count <= 260);
}

int main(void) {
  demonstrateCharOverflow();

  printf("Number of bits in char is %d.\n", CHAR_BIT);
  printf("CHAR_MAX is %d\n", CHAR_MAX);
  printf("CHAR_MIN is %d\n", CHAR_MIN);
  puts("");
  printf("SHRT_MAX is %d.\n", SHRT_MAX);
  printf("SHRT_MIN is %d.\n", SHRT_MIN);
  puts("");
  printf("INT_MAX is %d.\n", INT_MAX);
  printf("INT_MIN is %d.\n", INT_MIN);
  puts("");
  printf("LONG_MAX is %ld.\n", LONG_MAX);
  printf("LONG_MIN is %ld.\n", LONG_MIN);
}
