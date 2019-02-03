#include <TemplateMethod/Coffee.h>
#include <TemplateMethod/Tea.h>

int main(int argc, char *argv[]) {
  auto *tea = new Tea();
  auto *coffee = new Coffee();

  std::cout << "\nMaking tea..." << std::endl;
  tea->prepareRecipe();

  std::cout << "\nMaking Coffee..." << std::endl;
  coffee->prepareRecipe();

  return 0;
}
