#include <iostream>
#include <Strategy/MallardDuck.h>

int main(int argc, char *argv[])
{
    Duck *duck;
    MallardDuck *mallard = new MallardDuck();
    duck = mallard;
    duck->performFly();
    duck->display();
    duck->swim();
    return 0;
}
