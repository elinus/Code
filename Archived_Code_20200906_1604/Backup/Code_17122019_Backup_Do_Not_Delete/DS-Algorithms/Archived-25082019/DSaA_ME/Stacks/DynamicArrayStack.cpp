#include <iostream>
#include <climits>

struct DynamicArrayStack {
    int top;
    int capacity;
    int *array;
};

struct DynamicArrayStack* createStack(int capacity) {
    struct DynamicArrayStack *S = (struct DynamicArrayStack *)malloc(sizeof(struct DynamicArrayStack));
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

bool isEmpty(struct DynamicArrayStack* S) {
    return S->top == -1;
}

bool isFull(struct DynamicArrayStack* S) {
    return S->top == S->capacity - 1;
}

void doubleStack(struct DynamicArrayStack* S) {
    S->capacity *= 2;
    S->array = (int *)realloc(S->array, S->capacity);
}

void push(struct DynamicArrayStack* S, int data) {
    if (isFull(S)) doubleStack(S);
    S->array[++S->top] = data;
}

int pop(struct DynamicArrayStack *S) {
    if (isEmpty(S)) {
        std::cout << "Error: Stack is empty!" << std::endl;
        return INT_MIN;
    } else {
        return S->array[S->top--];   
    }
}

int peek(struct DynamicArrayStack *S) {
    if (isEmpty(S)) {
        std::cout << "Error: Stack is empty!" << std::endl;
        return INT_MIN;
    } else {
        return S->array[S->top];   
    }
}

void deleteStack(struct DynamicArrayStack *S) {
    if (S) {
        if (S->array) {
            free(S->array);
        }
        free(S);
    }
}

int main(int argc, char const *argv[]) {
    DynamicArrayStack *S = createStack(2);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    std::cout << pop(S) << std::endl;
    std::cout << pop(S) << std::endl;
    std::cout << peek(S) << std::endl;
    while (!isEmpty(S)) {
        std::cout << pop(S) << std::endl;
    }
    deleteStack(S);
    return 0;
}

