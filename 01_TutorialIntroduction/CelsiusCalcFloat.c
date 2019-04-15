#include <stdio.h>
/* Simple Fahrenheit to Celsius Converter
 * using floating point numbers.
 */
#define LOWER_LIMIT 0
#define UPPER_LIMIT 300
#define STEP 20
int main(void) {
  float fahr;
  for (fahr = 0.0; fahr <= UPPER_LIMIT; fahr += STEP) {
    printf("%6.2f\t%6.2f\n", fahr, (fahr - 32) * 5 / 9);
  }
  return 0;
}
