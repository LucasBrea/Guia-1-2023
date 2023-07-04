#include <stdio.h>
#include <stdlib.h>

int* merge(int* A, int sizeA, int* B, int sizeB) {
    int* C = (int*)(malloc(sizeof(int)*(sizeA+sizeB)));
    int* C_start = C;
    
    while (sizeA > 0 && sizeB > 0) {
        if (*A < *B) {
            *C = *A;
            C++;
            A++;
            sizeA--;
        } else {
            *C = *B;
            B++;
            C++;
            sizeB--;
        }
    }
    
    while (sizeA > 0) {
        *C = *A;
        C++;
        A++;
        sizeA--;
    }
    
    while (sizeB > 0) {
        *C = *B;
        B++;
        C++;
        sizeB--;
    }
    
    return C_start;
}

   


int main() {
   
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    int a[7] = {4,5,6,7,8,14,16};
    int b[6] = {1,2,3,9,14,125};

    int* result = merge(a, 7, b, 6);

    printf("Result:");
    for(int i=0; i<13; i++) {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);

    

   

    return 0;
}
