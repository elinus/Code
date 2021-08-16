// epoch.cpp
#include <chrono>
#include <iostream>


int main() {
  auto timeNow = std::chrono::system_clock::now();
  auto duration = timeNow.time_since_epoch();
  std::cout << duration.count() << "ns\n"; // nanoseconds (default)

  // duration_cast converts one type into the other
  auto durationSeconds =
      std::chrono::duration_cast<std::chrono::seconds>(duration).count();
  std::cout << durationSeconds << "s\n"; // seconds

  auto durationMinutes =
      std::chrono::duration_cast<std::chrono::minutes>(duration).count();
  std::cout << durationMinutes << "m\n"; // minutes

  return 0;
}