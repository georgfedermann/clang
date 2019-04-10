#include <stdio.h>
#define UPPER_LIMIT 300
#define LOWER_LIMIT 0
#define STEP 20

float convertFahrenheitToCelsius(float fahrenheit);

int main(void) {
  int fahr;
  for (fahr = UPPER_LIMIT; fahr >= LOWER_LIMIT; fahr -= STEP) {
    printf("%10.2d\t%10.2f\n", fahr, convertFahrenheitToCelsius(fahr));
  }

  return 0;
}

float convertFahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}
