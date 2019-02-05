#include "StopWatch.h"

StopWatch::StopWatch() : mStart(std::chrono::steady_clock::now()) {}

StopWatch::StopWatch(const StopWatch &other) : mStart(other.mStart) {}

StopWatch &StopWatch::operator=(const StopWatch &other) {
  mStart = other.mStart;
  return *this;
}

uint64_t StopWatch::ElapsedMs() const {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::steady_clock::now() - mStart)
      .count();
}

std::chrono::steady_clock::time_point StopWatch::Restart() {
  mStart = std::chrono::steady_clock::now();
  return mStart;
}
