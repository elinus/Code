#include <iostream>
#include <climits>

class StackNode {
    public:
        int data;
        StackNode *next;
};

StackNode* newNode(int data) {
    StackNode* node = new StackNode;
    node->data = data;
    node->next  = nullptr;
    return node;
}

bool isEmpty(StackNode *root) {
    return !root;
}

void push(StackNode** root, int data) {
    StackNode* node = newNode(data);
    node->next = *root;
    *root = node;
}

int pop(StackNode** root) {
    if (isEmpty(*root)) {
        return INT_MIN;
    }
    StackNode *temp = *root;
    int res = temp->data;
    *root = (*root)->next;
    delete temp;
    return res;
}

int peek(StackNode *root) {
    if (isEmpty(root)) {
        return INT_MIN;
    }
    return root->data;
}

int main(int argc, char const *argv[]) {
    StackNode *root = nullptr;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    std::cout << "[POP] => " << pop(&root) << std::endl;
    std::cout << "[PEEK] => " << peek(root) << std::endl;
    return 0;
}

