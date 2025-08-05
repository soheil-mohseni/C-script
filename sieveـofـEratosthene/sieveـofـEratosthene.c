#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eratosthenes(int n) {
  if (n < 2) {
        printf("No primes!");
        return;
  }
  char *is_prime = calloc(n + 1, sizeof(char));
  for (int i = 2; i * i <= n; ++i) {
    if (!is_prime[i]) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = 1;
    }
  }
  for (int i = 2; i <= n; ++i)
    if (!is_prime[i])
      printf("%d ", i);
    free(is_prime);
}
int main() {
  int input;
  printf("enter your number ");

  scanf(" %d", &input);
  eratosthenes(input);
  return 0;
}