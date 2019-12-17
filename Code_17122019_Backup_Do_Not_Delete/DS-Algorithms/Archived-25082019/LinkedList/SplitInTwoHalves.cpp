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

void splitInTwoHalves(Node *head, Node **head1, Node **head2) {

    if (head == nullptr) {
        return;
    }
    Node *fast = head;
    Node *slow = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    (*head1) = head;

    if (head->next != head) {
        (*head2) = slow->next;
    }

    fast->next = slow->next;
    slow->next = head;
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

    cout << "After spliting cll." << endl;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    splitInTwoHalves(head, &head1, &head2);
    printList(&head1);
    printList(&head2);
    return 0;
}

