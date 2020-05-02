#include <iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

void printList(Node **head)
{
    Node *curr = (*head);
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    printList(&head);
    return 0;
}
