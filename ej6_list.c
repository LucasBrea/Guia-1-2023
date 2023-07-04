#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* addLast(struct node* n, int data) {

    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    struct node* first= n;
    new_node->data= data;
    new_node->next= NULL;
    if(n == NULL){
        n=new_node;
        return new_node;
    }
    while(first->next != NULL){
        first=first->next;
    }
    first->next=new_node;
    
    return n;
}

struct node* removeFirst(struct node* n) {

    if(n->next == 0){
        return 0;
    }
    struct node* temp=n;
    temp=n->next;
    n->next= 0;

    return temp;
}

struct node* join(struct node* n1, struct node* n2) {

    struct node* resultado=(struct node*)(malloc(sizeof(struct node)));
    if(n1 == 0){
        return n2;
    }
    if(n2 == 0){
        return n1;
    }
    resultado=n1;
    while(n1->next != 0){
        n1=n1->next;
    }
    n1->next=n2;
    
    return resultado;
}

struct node* removeData(struct node* n, int data) {
    
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=n;
    while(temp->next != 0){
        if(temp->data == data){
            temp->data=0;
        }
        temp=temp->next;
        if(temp->data==data){
            temp->data=0;
        }
    }
    
    return n;
}


void printList(struct node* n) {
    printf("[");
    if(n == 0){
        printf("]\n");
    } else {
        while(n->next != 0){
            printf("%i, ", n->data);
            n = n->next;
        }
        printf("%i]\n", n->data);
    }
}

int main() {
    
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct node *n1 = NULL;
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n1\n");
    n1 = addLast(n1, 2021);
    n1 = addLast(n1, 42);
    n1 = addLast(n1, 0x400);
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n2\n");
    struct node *n2 = NULL;
    n2 = addLast(n2, 0);
    n2 = addLast(n2, 42);
    printList(n2);
    printf("\n");
   
    printf("Join lista n1 y n2: n3\n");
    struct node *n3 = join(n1, n2);
    printList(n3);
    printf("\n");

    printf("RemoveFirst: n3\n");
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");
    
    printf("RemoveData: 42\n");
    n3 = removeData(n3, 42);
    printList(n3);
    printf("\n");
    
    printf("RemoveFirst dos veces: n3\n");
    n3 = removeFirst(n3);
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");

    // */

    return 0;
}
