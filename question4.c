#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

int isPalindrome(struct Node* head) {
    if (head == NULL) return 1;

    struct Node* left = head;
    struct Node* right = head;

    while (right->next != NULL)
        right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main() {
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n5 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 'r'; n1->prev = NULL; n1->next = n2;
    n2->data = 'a'; n2->prev = n1;   n2->next = n3;
    n3->data = 'd'; n3->prev = n2;   n3->next = n4;
    n4->data = 'a'; n4->prev = n3;   n4->next = n5;
    n5->data = 'r'; n5->prev = n4;   n5->next = NULL;

    if (isPalindrome(n1))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
