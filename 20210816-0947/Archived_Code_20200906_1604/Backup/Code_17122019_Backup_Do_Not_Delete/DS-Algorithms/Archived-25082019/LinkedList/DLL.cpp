#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
};

void push(Node **headRef, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = (*headRef);
    newNode->prev = nullptr;
    if ((*headRef) != nullptr) {
        (*headRef)->prev = newNode;
    }
    (*headRef) = newNode;
}

void printList(Node **headRef) {
    Node *curr = (*headRef);
    Node *last = nullptr;
    cout << "[ -> ] ";
    while (curr) {
        cout << curr->data << " ";
        last = curr;
        curr = curr->next;
    }
    cout << "\n[ <- ] ";
    while (last) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << "\n";
}

int main (int argc, char const *argv[])
{
    Node *head = nullptr;
    push(&head, 14);
    push(&head, 20);
    push(&head, 24);
    push(&head, 11);
    push(&head, 16);
    printList(&head);
    return 0;
}

