#include <stdio.h>
#include <stdlib.h>


struct node {
	int value;
	struct node *next;
};

int sumList(struct node *list) {
    struct node *curr = list;
    int sum = 0;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

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
    printf("The sum of the list is: %d\n", sumList(head));
}