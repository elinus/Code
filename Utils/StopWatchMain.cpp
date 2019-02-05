#include "StopWatch.h"
#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
  StopWatch swObj;

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));

  std::cout << swObj.ElapsedMs() << std::endl;

  return 0;
}
