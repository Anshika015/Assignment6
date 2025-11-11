#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int sizee(Node* head) {
    if (head == NULL) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};
    head->next = second;
    second->next = third;
    third->next = head;  // make it circular

    cout << "Size of Circular Linked List: " << sizee(head);
    return 0;
}
