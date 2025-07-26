#include <stdio.h>

int gcd(int u, int v) {

  int t;
  if (u > v) {
    t = u;
    u = v;
    v = t;
  }
  while ((v % u) != 0) {
    t = u;
    u = (v % u);
    v = t;
    printf("%d %d \n",u,v);
  }
  return u;
}

int main() {
  int x, y;

  while (scanf("%d %d", &x, &y) != EOF) {
    printf(" the gcd of %d and %d is = %d \n ", x, y, gcd(x, y));
  }

  return 0;
}