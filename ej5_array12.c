#include <stdio.h>
#include <stdlib.h>

int sumAsBytes(char* v) {
    int res;
    for(int i=0;i<12;i++){
        res+=*v;
        v++;
    }
    return 0;
}

int sumAsInts(int* v) {
    int res;
    int temp;
    for(int i=0;i<4;i++){
        res+=*v;
        v++;
    }
    
    return 0;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[12] = {0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00,0x05,0x01,0x00,0x00};

    int sumB = sumAsBytes((char*)v);
    int sumI = sumAsInts((int*)v);

    printf("El arreglo sumado de a bytes es: %i (d) %x (h)\n", sumB, sumB);
    printf("El arreglo sumado de a ints es: %i (d) %x (h)\n", sumI, sumI);

    // */

    return 0;
}