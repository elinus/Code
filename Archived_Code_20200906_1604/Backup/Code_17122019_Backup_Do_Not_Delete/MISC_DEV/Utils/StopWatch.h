#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#include <chrono>

class StopWatch {
public:
  StopWatch();
  StopWatch(const StopWatch &other);
  StopWatch &operator=(const StopWatch &other);
  uint64_t ElapsedMs() const;
  std::chrono::steady_clock::time_point Restart();

private:
  std::chrono::steady_clock::time_point mStart;
};

#endif /* __STOPWATCH_H__ */
