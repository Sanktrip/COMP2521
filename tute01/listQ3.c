#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void listDelete(struct list *l, int value) {
    struct node *prev = NULL;
    // If the head of the list is NULL, return
    if (l->head == NULL) {
        return;
    }

    // Head of the list is the value
    if (l->head->value == value) {
        struct node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        return;
    }

    for (struct node *curr = l->head; curr != NULL; curr = curr->next) {
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            free(curr);
            return;
        }
        prev = curr;
    }   
    return;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addNode(struct list *l, int val) {
    struct node *temp = l->head;
    struct node *new = malloc(sizeof(struct node));
    new->value = val;
    new->next = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

int main (int argc, char *argv[]) {
    struct list *l = malloc(sizeof(struct list));
    if (argc < 2) {
        l->head = NULL;
    } else {
        l->head = malloc(sizeof(struct node));
        l->head->value = atoi(argv[1]);
        l->head->next = NULL;
    }
    for (int i = 2; i < argc; i++) {
        addNode(l, atoi(argv[i]));
    }
    printf("Initial list:\n");
    printList(l->head);
    printf("Choose element to delete: ");
    int delete;
    scanf("%d", &delete);
    listDelete(l, delete);
    printList(l->head);
}