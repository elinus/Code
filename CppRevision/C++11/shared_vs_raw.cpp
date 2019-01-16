#include <iostream>
#include <memory>

class Test {
    public:
        void print(){
            std::cout << "Test::print()\n";
        }
};

int main (int argc, char *argv[])
{
    std::shared_ptr<Test> p1(new Test());
    (*p1).print();
    p1->print();
    //p1++; // error: no ‘operator++(int)’ declared for postfix ‘++’ [-fpermissive]
    //p1--; // error: no ‘operator--(int)’ declared for postfix ‘--’ [-fpermissive]
    //p1[0]->print(); //  error: no match for ‘operator[]’ (operand types are ‘std::shared_ptr<Test>’ and ‘int’)

    std::shared_ptr<Test> p2;
    if (!p2) {
        std::cout << "Empty\n";
    }

    std::cout << "p1 = " << p1 << std::endl;
    Test *raw_ptr = p1.get();
    std::cout << "raw_ptr = " << raw_ptr << std::endl;
    return 0;
}

