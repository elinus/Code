#include <Adapter/Duck.h>
#include <Adapter/MallardDuck.h>
#include <Adapter/WildTurkey.h>
#include <Adapter/TurkeyAdapter.h>
#include <iostream>

void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}

int main(int argc, char *argv[])
{
    MallardDuck *duck = new MallardDuck();
    WildTurkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);
    
    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "The Duck says..." << std::endl;
    testDuck(duck);

    std::cout << "The TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);
    return 0;
}
