#include "ThreadPoolManager.h"
#include <iostream>

#define EXPECT_EQUAL(test, expect) equalityTest(test, expect, #test, #expect, __FILE__, __LINE__)

template<typename T1, typename T2>
int equalityTest(
        const T1 testValue,
        const T2 expectedValue,
        const char* testName,
        const char* expectedName,
        const char* fileName,
        const int lineNumber
        );

int main (int argc, char *argv[]) {
    ThreadPoolManager *poTPM = ThreadPoolManager::GetThreadPoolManager();

    int result = 0;


    poTPM->AddTask("write code");
    poTPM->AddTask("compile");
    poTPM->AddTask("test");

    result |= EXPECT_EQUAL(poTPM->Size(), 3);
    result |= EXPECT_EQUAL(poTPM->GetTask(0), "write code");
    result |= EXPECT_EQUAL(poTPM->GetTask(1), "compile");
    result |= EXPECT_EQUAL(poTPM->GetTask(2), "test");

    if (result == 0) {
        std::cout << "Test passed!\n";
    }

    poTPM->DestroyThreadPoolManagerInstance();
    return 0;
}


template <typename T1, typename T2>
int equalityTest(
        const T1    testValue,
        const T2    expectedValue,
        const char* testName,
        const char* expectedName,
        const char* fileName,
        const int   lineNumber
        )
{
    if (testValue != expectedValue) {
        std::cerr << fileName << ":" << lineNumber << ": " 
            << "Expected " << testName << " " 
            << "to equal " << expectedName << " (" << expectedValue << ") "
            << "but it was (" << testValue << ")\n";
        return 1;
    } else {
        return 0;
    }
}

