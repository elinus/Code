// https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
#include <iostream>
#include <memory>

struct Task
{
    int mId;
    Task(int id ) :mId(id)
    {
        std::cout<<"Task::Constructor"<<std::endl;
    }
    ~Task()
    {
        std::cout<<"Task::Destructor"<<std::endl;
    }
};

int main()
{
    // Empty unique_ptr object
    std::unique_ptr<int> ptr1;

    // Check if unique pointer object is empty
    if(!ptr1)
        std::cout<<"ptr1 is empty"<<std::endl;

    // Check if unique pointer object is empty
    if(ptr1 == nullptr)
        std::cout<<"ptr1 is empty"<<std::endl;

    // can not create unique_ptr object by initializing through assignment
    // std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error

    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr(new Task(23));

    // Check if taskPtr is empty or it has an associated raw pointer
    if(taskPtr != nullptr)
        std::cout<<"taskPtr is  not empty"<<std::endl;

    //Access the element through unique_ptr
    std::cout<<taskPtr->mId<<std::endl;

    std::cout<<"Reset the taskPtr"<<std::endl;
    // Reseting the unique_ptr will delete the associated
    // raw pointer and make unique_ptr object empty
    taskPtr.reset();

    // Check if taskPtr is empty or it has an associated raw pointer
    if(taskPtr == nullptr)
        std::cout<<"taskPtr is  empty"<<std::endl;


    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr2(new Task(55));

    if(taskPtr2 != nullptr)
        std::cout<<"taskPtr2 is  not empty"<<std::endl;

    // unique_ptr object is Not copyable
    //taskPtr = taskPtr2; //compile error

    // unique_ptr object is Not copyable
    //std::unique_ptr<Task> taskPtr3 = taskPtr2;

    {
        // Transfer the ownership

        std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);


        if(taskPtr2 == nullptr)
            std::cout<<"taskPtr2 is  empty"<<std::endl;

        // ownership of taskPtr2 is transfered to taskPtr4
        if(taskPtr4 != nullptr)
            std::cout<<"taskPtr4 is not empty"<<std::endl;

        std::cout<<taskPtr4->mId<<std::endl;

        //taskPtr4 goes out of scope and deletes the assocaited raw pointer
    }

    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr5(new Task(55));

    if(taskPtr5 != nullptr)
        std::cout<<"taskPtr5 is not empty"<<std::endl;

    // Release the ownership of object from raw pointer
    Task * ptr = taskPtr5.release();

    if(taskPtr5 == nullptr)
        std::cout<<"taskPtr5 is empty"<<std::endl;

    std::cout<<ptr->mId<<std::endl;

    delete ptr;

    return 0;
}
