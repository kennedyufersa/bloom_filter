#define MAX 1000000
#include <stdio.h>

int V[MAX] = {0};
void primos();
void eliminarMultiplos(int n);

int main() { primos(); }

void primos() {
  int p = 2;
  while (p * p < MAX) {
    printf("%d ", p);
    eliminarMultiplos(p);
    do {
      p = p + 1;
    } while (V[p] != 0);
  }
  printf("\n");
}

void eliminarMultiplos(int n) {
  for (size_t i = 2 * n; i < MAX; i = i + n) {
    V[i] = 1;
  }
}
