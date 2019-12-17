#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

void push(Node **head, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    Node *curr = (*head);
    if ((*head) != nullptr) {
        while (curr->next != (*head)) {
            curr = curr->next;
        }
        curr->next = newNode;
    } else {
        newNode->next = newNode;
    }
    (*head) = newNode;
}

void printList(Node **head) {
    Node *curr = (*head);
    if (curr != nullptr) {
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != (*head));
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

