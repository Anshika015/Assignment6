#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void display(struct Node *head) {
    if (!head) return;
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d\n", head->data);
}

int main() {
    struct Node *head = NULL, *temp = NULL;
    int arr[] = {20, 100, 40, 80, 60}, i;
    for (i = 0; i < 5; i++) {
        struct Node *n = createNode(arr[i]);
        if (!head) head = n;
        else temp->next = n;
        temp = n;
    }
    temp->next = head;
    display(head);
    return 0;
}
