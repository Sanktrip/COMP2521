#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/* Iterative 
int listLength(struct node *l) {
    int count = 0;
    for (struct node *curr = l; curr != NULL; curr = curr->next) {
        count++;
    }
    return count;
} */



// Recursive
int listLength(struct list *l) {
  
} 


/* Iterative
int listCountOdds(struct node *l) {
    int count = 0;
    for (struct node *curr = l; curr != NULL; curr = curr->next) {
        if (curr->value % 2) {
            count++;
        }
    }
    return count;
} */

// Recursive 
int listCountOdds(struct node *l) {
    // base case
    if (!l) {
        return 0;
    }
    if (l->value % 2) {
        return 1 + listCountOdds(l->next);
    } else {
        return listCountOdds(l->next);
    }
} 

/* Iterative
bool listIsSorted(struct node *l) {
    return true;
} */

// Recursive
bool listIsSorted(struct node *l) {
    // base case
    if (!l) {
        return true;
    }
    if (!l->next) {
        return true;
    }
    if (l->value > l->next->value) {
        return false;
    } else {
        return listIsSorted(l->next);
    }
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
    printList(head);
    printf("The length of the list is: %d\n", listLength(head));
    printf("Odd numbers: %d\n", listCountOdds(head));
    if (listIsSorted(head)) {
        printf("The list is sorted\n");
    } else {
        printf("The list is not sorted\n");
    }


}