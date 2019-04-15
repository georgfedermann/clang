#include <stdio.h>

// print the size of various data types

int main() {
  int someInt;
  printf("Size of uninitialized int variable is %ld.\n", sizeof(someInt));
  someInt = 5;
  printf("Size of int variable set to 5 is %ld.\n", sizeof(someInt));
  someInt = 255;
  printf("Size of int variable set to 255 is %ld.\n", sizeof(someInt));
  printf("Size of literal 5 is %ld.\n", sizeof(5));
  float someFloat;
  printf("Size of unitialized float variable is %ld.\n", sizeof(someFloat));
  someFloat = 3.14159265;
  printf("Size of float var set to 3.14159265 is %ld.\n", sizeof(someFloat));
  printf("Size of 2147483647 is %ld.\n", sizeof(2147483647));
  printf("Size of 2147483648 is %ld.\n", sizeof(2147483648));

  int intArray[8];
  printf("The size of an int array with 8 elements is %ld.\n",
         sizeof(intArray));

  char aChar = '\n';
  printf("The size of char is %ld.\n", sizeof(aChar));

  return 0;
}
