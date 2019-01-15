#include <iostream>
#include <string>

class Person {
    private:
        std::string name;
    public:
        void setName(std::string name){
            this->name = name;
        }
        void print()
        {
            std::cout << name << std::endl;
            [this](){
                std::cout << "lambda: " << name << std::endl;
            };
        }
};

int main (int argc, char *argv[])
{
    Person po;
    po.setName("elinus");
    po.print();
    return 0;
}

