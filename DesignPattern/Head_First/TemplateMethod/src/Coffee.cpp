#include <TemplateMethod/Coffee.h>

void Coffee::brew() {
  std::cout << "Dripping Coffee through filter" << std::endl;
}

void Coffee::addCondiments() {
  std::cout << "Adding Sugar and Milk" << std::endl;
}

bool Coffee::customerWantsCondiments() {
  std::string answer = getUserInput();
  if (::tolower(answer[0]) == 'y') {
    return true;
  } else {
    return false;
  }
}

std::string Coffee::getUserInput() {
  std::string answer = "";
  std::cout << "Would you like milk and sugar with coffee (y/n)? ";
  std::cin >> answer;
  if (answer == "") {
    return "no";
  }
  return answer;
}
