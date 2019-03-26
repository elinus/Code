#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void printList(Node **head_ref)
{
    Node *curr = (*head_ref);
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(int argc, char const *argv[])
{
    Node *head = nullptr;
    push(&head, 12);
    push(&head, 14);
    printList(&head);
    return 0;
}
