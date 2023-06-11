#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct node *listDelete(struct node *l, int value) {
    // base case 
    if (!l) {
        return NULL;
    }
    if (l->value == value) {
        struct node *temp = l->next;
        free(l);
        return temp;
    }
    l->next = listDelete(l->next, value);
    return l;
} 

struct node *listDeleteEvens(struct node *l) {
    // base case
    if (!l) return NULL;
    if (!(l->value % 2)) {
        struct node *temp = l->next;
        free(l);
        temp = listDeleteEvens(temp);
        return temp;
    } else {
        l->next = listDeleteEvens(l->next);
    }
    return l;
}

int main (int argc, char *argv[]) {
    struct node *head;
    if (argc < 2) {
        head = NULL;
    } else {
        head = malloc(sizeof(struct node));
        head->value = atoi(argv[1]);
        head->next = NULL;
    }
    for (int i = 2; i < argc; i++) {
        head = addNode(head, atoi(argv[i]));
    }
    printf("Initial List:\n");
    printList(head);
    printf("List after odds are deleted: \n");
    head = listDeleteEvens(head);
    printList(head);
    

}