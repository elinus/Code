#include <TemplateMethod/Tea.h>

void Tea::brew() { std::cout << "Steeping the tea" << std::endl; }

void Tea::addCondiments() { std::cout << "Adding Lemon" << std::endl; }

bool Tea::customerWantsCondiments() {
  std::string answer = getUserInput();
  if (::tolower(answer[0]) == 'y') {
    return true;
  } else {
    return false;
  }
}

std::string Tea::getUserInput() {
  std::string answer = "";
  std::cout << "Would you like milk and sugar with tea (y/n)? ";
  std::cin >> answer;
  if (answer == "") {
    return "no";
  }
  return answer;
}
