#define MAX 1000000
#define NUM_BYTES 32
#include <stdio.h>
#include <stdlib.h>

int V[MAX] = {0};

struct filtro_blooom {
  char bytes[NUM_BYTES];
};

struct filtro_blooom filtro;

void primos();
void consultarPrimo(int);
void eliminarMultiplos(int n);
int procurarByte(int x);
int procurarBit(int x);
int hash1(int);
int hash2(int);
int hash3(int);
void inserir(int, int, int (*f[])(int));

int main(int argc, char *argv[]) { primos(); }

int procurarByte(int x) { return x / 8; }
int procurarBit(int x) { return x % 8; }

void inserir(int x, int hs, int (*f[])(int)) {
  int h[hs];
  for (int i = 0; i < hs; i++) {
    h[i] = f[i](x);
    int byte = procurarByte(h[i]);
    int bit = procurarBit(h[i]);
    filtro.bytes[byte] = filtro.bytes[byte] | (1 << bit);
  }
}

int hash1(int x) { return x % (NUM_BYTES * 8); }
int hash2(int x) { return (3 * x + 7) % (NUM_BYTES * 8); }
int hash3(int x) { return (5 * x + 11) % (NUM_BYTES * 8); }

void consultarPrimo(int x) {
  int (*f[3])(int) = {hash1, hash2, hash3};
  int h[3] = {0};
  for (int i = 0; i < 3; i++) {
    h[i] = f[i](x);
    int byte = procurarByte(h[i]);
    int bit = procurarBit(h[i]);
    char b = filtro.bytes[byte];
    //Construir a máscara para validar se o número é pimo.
  }
}

void primos() {
  int p = 2;
  int (*f[3])(int) = {hash1, hash2, hash3};
  while (p * p < MAX) {
    inserir(p, 3, f);
    eliminarMultiplos(p);
    do {
      p = p + 1;
    } while (V[p] != 0);
  }
}

void eliminarMultiplos(int n) {
  for (size_t i = 2 * n; i < MAX; i = i + n) {
    V[i] = 1;
  }
}
