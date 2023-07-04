#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node *first;
    int size;
};

struct node {
    struct node *next;
    struct node *prev;
    char *data;
};

struct list* listNew() {
    struct list* l = (struct list*)malloc(sizeof(struct list));
    l->first = 0;
    l->size = 0;
    return l;
}

void listDelete(struct list* l) {
    struct node* n = l->first;
    while ( n != 0 ) {
        struct node* r = n;
        n = n->next;
        free(r);
    }
    free(l);
}

void listPrint(struct list* l) {
    struct node* n = l->first;
    printf("[");
    while ( n != 0 ) {
        printf("\"%s\"", n->data);
        n = n->next;
        if( n != 0 ) {
            printf(",");
        }
    }
    printf("]");
}

struct list* addFirst(struct list* l, char* data) {

    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(l->first == 0){
        new_node->data=data;
        new_node->prev=0;
        new_node->next=0;
        l->first=new_node;
    }else{
    new_node->data=data;
    new_node->prev=0;
    new_node->next=l->first;
    l->first->prev=new_node;
    l->first=new_node;
    }
    return l;
}

struct list* removeFirst(struct list* l) {
    struct node* temp=l->first->next;
    l->first->next->prev=0;
    l->first->next=0;
    l->first=temp;
    
    
    return l;
}

struct list* removeNode(struct list* l, struct node* n) {
    struct node* curr = l->first;
    
    
    if(curr == n){
        l->first = n->next;
        if(n->next != 0) 
        n->next->prev = 0;
        n->next = 0;
        return l;
    }
    
    
    while(curr != 0){
        if(curr == n){
            
            curr->prev->next = curr->next;
            
            if(curr->next != 0) 
            
            curr->next->prev = curr->prev;
            n->prev = 0;
            n->next = 0;
            return l;
        }
        curr = curr->next;
    }
    
    
    return l;
}
struct list* removeNodei(struct list* l, int i) {
    if (l->first == NULL) {

        return l;
    }
    struct node* curr = l->first;
    int j = 0;
    while (curr != NULL) {
        if (j == i) {
            
            if (curr == l->first) {
                //si curr es el primer nodo
                l->first = curr->next;
                if (l->first != NULL) {
                    l->first->prev = NULL;
                }
            } else {
                //elimino cualquier otro nodo
                curr->prev->next = curr->next;
                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                }
            }
            free(curr);
            return l;
        }
        curr = curr->next;
        j++;
    }
    
    return l;
}

    


int main() {
  
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct list* l = listNew();
    l = addFirst(l, "back");
    struct node* toRemove1 = l->first;
    l = addFirst(l, "swim");
    l = addFirst(l, "for");
    l = addFirst(l, "anything");
    struct node* toRemove2 = l->first;
    l = addFirst(l, "save");
    l = addFirst(l, "never");
    struct node* toRemove3 = l->first;
    l = addFirst(l, "I");
    listPrint(l);
    printf("\n\n");

    printf("RemoveFirst\n");
    l = removeFirst(l);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove1->data);
    l = removeNode(l, toRemove1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove2->data);
    l = removeNode(l, toRemove2);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNode: %s\n", toRemove3->data);
    l = removeNode(l, toRemove3);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 1\n");
    l = removeNodei(l, 1);
    listPrint(l);
    printf("\n\n");

    printf("RemoveNodei: 0\n");
    l = removeNodei(l, 0);
    listPrint(l);
    printf("\n\n");

    listDelete(l);

 

    return 0;
}
