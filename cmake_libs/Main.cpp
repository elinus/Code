#include "Helloworld.h"

int main(int argc, char *argv[])
{
    Helloworld *h_ptr = new Helloworld();
    h_ptr->sayHello(14);
    return 0;
}
