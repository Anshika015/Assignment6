#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int sizee(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node{10, NULL, NULL};
    head->next = new Node{20, head, NULL};
    head->next->next = new Node{30, head->next, NULL};

    cout << "Size of Doubly Linked List: " << sizee(head);
    return 0;
}
