#include <stdio.h>
#include <stdlib.h>

void stringToUppercase(char* s){
    while(*s != '\0'){
        if(*s<= 122 && *s>=97){
            *s-=32;
        }
        s++;
    }

}

int len(char* s) {
    int i=0;
    while(s[i]!= '\0'){
        i++;
    }

    return i;
}

char* copy(char* s) {
    char *s2=(char*)malloc((sizeof(char)*len(s))+1);
    int i=0;
    while(s[i] != '\0'){
        s2[i]=s[i];
        i++;
    }
    s2[i]='\0';
    return s2;
}

int main(){

    char* a="Hola Carola";
    char* b= copy(a);
    stringToUppercase(b);
    printf("%s",b);
    


}