#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

void printList(Node **head_ref)
{
    Node *curr = (*head_ref);
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void push(Node **head_ref, int data)
{
    Node *new_node = new Node(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(Node **head_ref, int data)
{
    Node *new_node = new Node(data);
    if ((*head_ref) == nullptr)
    {
        (*head_ref) = new_node;
        return;
    }
    Node *curr = (*head_ref);
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void insertAfter(Node *prev_node, int data)
{
    if (prev_node == nullptr)
    {
        cout << "Error: previous node is null." << endl;
        return;
    }

    Node *new_node = new Node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main(int argc, char const *argv[])
{
    Node *head = nullptr;
    push(&head, 12);
    push(&head, 14);
    append(&head, 20);
    insertAfter(head->next, 24);
    printList(&head);
    return 0;
}
