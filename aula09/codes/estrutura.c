#define NUM_BYTES 32
#include <stdlib.h>
struct filtro_blooom {
  char bytes[NUM_BYTES];
};

int procurarByte(int x);
int procurarBit(int x);

int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);
    printf("Byte %d, Bit %d", procurarByte(x), procurarBit(x));
}

int procurarByte(int x) { return x / 8; }
int procurarBit(int x) { return x % 8; }