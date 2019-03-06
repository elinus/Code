#include <iostream>

using namespace std;

template <typename T, typename U>
void fillArray(T *array, size_t arraySize, U func)
{
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = func();
    }
}

template <typename T>
void printArray(T *array, size_t arraySize)
{
    cout << "Array elems: ";
    for (int i = 0; i < arraySize; ++i)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void nonTemplateFillArray(int *array, size_t arraySize, int (*func)(void))
{
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = func();
    }
}

int fillWithInts()
{
    return rand();
}

char fillWithChars()
{
    return char('A' + rand() % 24);
}

int main()
{
    int intArray[10];

    fillArray(intArray, 10, fillWithInts);
    printArray(intArray, 10);

    nonTemplateFillArray(intArray, 10, fillWithInts);
    printArray(intArray, 10);

    char charArray[10];

    fillArray(charArray, 10, fillWithChars);
    printArray(charArray, 10);
    return 0;
}