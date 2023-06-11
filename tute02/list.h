#include <stdio.h>
#include <stdlib.h>


struct node {
	int value;
	struct node *next;
};

struct node* addNode(struct node *head, int val) {
    struct node *temp = head;
    struct node *new = malloc(sizeof(struct node));
    new->value = val;
    new->next = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return head;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}