#include <iostream>
#include <string>

class Employee {
    private:
        int mId;
        std::string mName;
    public:
        Employee(int id = 0, const std::string& name = "")
            : mId(id), mName(name) {
                std::cout << "Employee " << mName << " created!\n";
            }
        Employee(const std::string& name) : Employee(0, name) {}
};

int main (int argc, char *argv[]) {
    
    return 0;
}

