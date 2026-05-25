#define NUM_BYTES 32
#include <stdio.h>
#include <stdlib.h>
struct filtro_blooom {
  char bytes[NUM_BYTES];
};
int procurarByte(int x);
int procurarBit(int x);
int hash1(int);
int hash2(int);
int hash3(int);
void inserir(int, int, int (*f[])(int));

int main(int argc, char *argv[]) {
  int x = atoi(argv[1]);
  int (*f[3])(int) = {hash1, hash2, hash3};
  inserir(x, 3, f);
}

int procurarByte(int x) { return x / 8; }
int procurarBit(int x) { return x % 8; }

void inserir(int x, int hs, int (*f[])(int)){
    int h[hs];
    for(int i=0; i<hs; i++){
        h[i] = f[i](x);
        printf("%d\n", h[i]);
    }
}

int hash1(int x) { return x % (NUM_BYTES * 8); }
int hash2(int x) { return (3 * x + 7) % (NUM_BYTES * 8); }
int hash3(int x) { return (5 * x + 11) % (NUM_BYTES * 8); }