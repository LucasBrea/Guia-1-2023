#include <stdio.h>
#include <stdlib.h>

void pairOfEquals(char v[], int size, char** a, char** b) {

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(v[i]==v[j] && i!=j){
                *a=&v[i];
                *b=&v[j];
            }

        }
    }

}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[7] = {9, 4, 5, 6, 1, 4, 10};

    char* a;
    char* b;

    pairOfEquals(v, 7, &a, &b);

    if(a == 0 || b == 0) {
        printf("No hay iguales");
    } else {
        printf("Los valores iguales son: %i == %i\n", (char)(*a), (char)(*b));
    }

    return 0;
}
