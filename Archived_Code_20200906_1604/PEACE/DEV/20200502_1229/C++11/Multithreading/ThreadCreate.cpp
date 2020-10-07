#include <iostream>
#include <thread>

void foo() {
  for (auto i = 0; i < 5; ++i) {
    std::cout << "foo = " << std::this_thread::get_id() << "\n";
  }
}

class Bar {
public:
  void operator()() {
    for (auto i = 0; i < 5; ++i) {
      std::cout << "Bar :: operator = " << std::this_thread::get_id() << "\n";
    }
  }
};

int main(int argc, char *argv[]) {
  std::thread th_func_obj{Bar()};
  std::cout << "th_func_obj :: id = " << th_func_obj.get_id() << "\n";

  std::thread th_func_ptr{foo};
  std::thread th_func_lambda([]() {
    for (auto i = 0; i < 5; ++i) {
      std::cout << __func__ << " :: lambda = " << std::this_thread::get_id()
                << "\n";
    }
  });

  if (th_func_obj.joinable()) {
    th_func_obj.join();
  }
  th_func_ptr.join();
  th_func_lambda.join();

  std::cout << "main = " << std::this_thread::get_id() << "\n";

  return 0;
}
