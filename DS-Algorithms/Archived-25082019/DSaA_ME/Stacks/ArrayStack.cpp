#include <iostream>
#include <climits>

struct ArrayStack {
    int top;
    int capacity;
    int *array;
};

struct ArrayStack* createStack(int capacity) {
    struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    if (!S) {
        std::cout << "Error: Not sufficient memory <Stack struct>." << std::endl;
        return nullptr;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = (int *)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        std::cout << "Error: Not sufficient memory <Stack array>." << std::endl;
        return nullptr;
    }
    return S;
}

bool isEmpty(struct ArrayStack* S) {
    return S->top == -1;
}

bool isFull(struct ArrayStack* S) {
    return S->top == S->capacity - 1;
}

void push(struct ArrayStack* S, int data) {
    if (isFull(S)) {
        std::cout << "Error: Stack overflow!" << std::endl;
    } else {
        S->array[++S->top] = data;
    }
}

int pop(struct ArrayStack *S) {
    if (isEmpty(S)) {
        std::cout << "Error: Stack is empty!" << std::endl;
        return INT_MIN;
    } else {
        return S->array[S->top--];   
    }
}

int peek(struct ArrayStack *S) {
    if (isEmpty(S)) {
        std::cout << "Error: Stack is empty!" << std::endl;
        return INT_MIN;
    } else {
        return S->array[S->top];   
    }
}

void deleteStack(struct ArrayStack *S) {
    if (S) {
        if (S->array) {
            free(S->array);
        }
        free(S);
    }
}

int main(int argc, char const *argv[]) {
    ArrayStack *S = createStack(2);
    push(S, 1);
    push(S, 2);
    std::cout << pop(S) << std::endl;
    push(S, 3);
    std::cout << pop(S) << std::endl;
    std::cout << peek(S) << std::endl;
    while (!isEmpty(S)) {
        std::cout << pop(S) << std::endl;
    }
    deleteStack(S);
    return 0;
}

