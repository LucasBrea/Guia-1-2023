#include <stdio.h>
#include <stdlib.h>

int len(char* s) {
    int i=0;
    while(s[i]!= '\0'){
        i++;
    }

    return i;
}
char* concatenate(char* s1, char* s2) {

    char* s3=(char*)malloc(sizeof(char)*(len(s1)+len(s2)));
    int i=0;
    int j=0;
    while(s1[i] != '\0'){
        s3[i]=s1[i];
        i++;
    }
    while(s2[j] != '\0'){
        s3[i]=s2[j];
        j++;
        i++;
    }
    s3[i]='\0';
    
    
    return s3;
}


char* longest(char* v[], int size) {

    char* result="";
    for(int i=0;i<size-1;i++){
        if(len(v[i])>len(v[i+1]) && len(result)<len(v[i])){
            result=v[i];
        }
    }

    return result ;
}

char* superConcatenate(char* v[], int size) {
    int largo=0;
    for(int i=0;i<size;i++){
        largo+=len(v[i]);
    }
    char* result=(char*)malloc(sizeof(char)*largo);
    for(int i=0;i<size;i++){
       result=concatenate(result,v[i]);

    }


    return result;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {
    int largo=0;
    for(int i=0;i<size;i++){
        largo+=len(v[i]);
    }
    for(int i=0;i<size-1;i++){
        largo+=len(s);
    }
    char* result=(char*)malloc(sizeof(char)*(largo));
    char* temp=(char*)malloc(sizeof(char)*largo);
    for(int i=0;i<size-1;i++){
        temp=concatenate(v[i],s);
        result=concatenate(result,temp);
    }
    result=concatenate(result,v[size-1]);

    return result;
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char* v[5] = {"hola", "como", "va", "el", "dia"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    char* scs = superConcatenateWithSep(v, 5, "...");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);

  

    return 0;
}
