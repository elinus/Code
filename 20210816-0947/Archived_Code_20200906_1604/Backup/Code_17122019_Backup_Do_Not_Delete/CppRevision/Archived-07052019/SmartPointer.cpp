#include <iostream>
#include <memory>

class Task {
    private:
        int id;
    public:
        Task(int id): id(id) {
            std::cout << "Task::Constructor" << std::endl;
        }
        ~Task() {
            std::cout << "Task::Destructor" << std::endl;
        }
        void setTaskId(int id) {
            this->id = id;
        }
        int getTaskId() {
            return id;
        }
};

int main (int argc, char const *argv[])
{
    std::unique_ptr<Task> p1(new Task(14));
    std::cout << "p1 = " << *p1 << std::endl;
    return 0;
}

