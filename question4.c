#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;
    while (right->next != NULL)
        right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* n1 = new Node{'r', NULL, NULL};
    Node* n2 = new Node{'a', n1, NULL};
    Node* n3 = new Node{'d', n2, NULL};
    Node* n4 = new Node{'a', n3, NULL};
    Node* n5 = new Node{'r', n4, NULL};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    if (isPalindrome(n1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
