#include <stdio.h>
#include <stdlib.h>
// accessing environment variables from within c code

#define ENV_VAR_NAME "HOME"

void printUsage() {
  printf("\nUsage: env [environmentVariableName]\n\n");
  printf("Prints the value of the given environment variable(s).\n");
  printf("If no environment variable is given, prints all variables found.\n");
}

void printEnvironmentVariable(char *variableName) {
  printf("%s=%s\n", variableName, getenv(variableName));
}

int main(int argCount, char **argValues) {
  if (argCount == 0 || argCount == 1) {
    printUsage();
  } else {
    int c;
    for (c = 1; c < argCount; c++) {
      printEnvironmentVariable(argValues[c]);
    }
  }
  return 0;
}
