#include <TemplateMethod/Tea.h>
#include <TemplateMethod/Coffee.h>

int main(int argc, char *argv[])
{
    Tea *tea = new Tea();
    Coffee *coffee = new Coffee();

    std::cout << "\nMaking tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << "\nMaking Coffee..." << std::endl;
    coffee->prepareRecipe();

    return 0;
}
