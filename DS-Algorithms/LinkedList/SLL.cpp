#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data): data(data), next(nullptr) {}
};

void printList(Node *head) {
    Node *curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void push(Node **head_ref, int data) {
    Node *new_node = new Node(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(Node **head_ref, int data) {
    Node *new_node = new Node(data);
    if ((*head_ref) == nullptr) {
        (*head_ref) = new_node;
        return;
    }
    Node *curr = (*head_ref);
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void insertAfter(Node *prev_node, int data) {
    if (prev_node == nullptr) {
        cout << "Error: previous node is null." << endl;
        return;
    }
    Node *new_node = new Node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(Node **head_ref, int key) {
    Node *curr = (*head_ref), *prev;
    if (curr != nullptr && curr->data == key) {
        (*head_ref) = curr->next;
        delete curr;
        return;
    }
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) return;
    prev->next = curr->next;
    delete curr;
}

int main(int argc, char const *argv[]) {
    Node *head = nullptr;
    push(&head, 14);
    append(&head, 20);
    printList(head);
    push(&head, 11);
    push(&head, 16);
    insertAfter(head->next->next, 24);
    printList(head);
    push(&head, 21);
    append(&head, 28);
    printList(head);
    deleteNode(&head, 21);
    deleteNode(&head, 28);
    printList(head);
    return 0;
}
