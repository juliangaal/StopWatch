/* 
 * File:   StopWatch.cpp
 * Author: Julian Gaal
 * From: https://github.com/juliangaal/StopWatch
 * 
 * Created on 2018-29-06
 */

#include "../include/StopWatch.hpp"

StopWatch::StopWatch() : start(Clock::now()),
                         pauseDuration(0),
                         paused(false) {
  static_assert(Clock::is_steady, "Serious OS/C++ library issues. Steady Clock is not steady");
}

StopWatch::StopWatch(const StopWatch &other) : start(other.start),
                                               pauseDuration(0),
                                               paused(false) {}

StopWatch &StopWatch::operator=(const StopWatch &rhs) {
  start = rhs.start;
  return *this;
}

rep StopWatch::ElapsedNs() const {
  return duration_cast<nanoseconds>(Clock::now() - start - pauseDuration).count();
}

rep StopWatch::ElapsedUs() const {
  return duration_cast<microseconds>(Clock::now() - start - pauseDuration).count();
}

rep StopWatch::ElapsedMs() const {
  return duration_cast<milliseconds>(Clock::now() - start - pauseDuration).count();
}

rep StopWatch::ElapsedSec() const {
  return duration_cast<seconds>(Clock::now() - start - pauseDuration).count();
}

void StopWatch::Restart() {
  start = Clock::now();
}

Clock::time_point StopWatch::RestartPoint() {
  Restart();
  return start;
}

void StopWatch::Pause() {
  if (!paused) {
    pause = Clock::now();
    paused = true;
  }
}

void StopWatch::Resume() {
  if (paused) {
    pauseDuration += (Clock::now() - pause);
    paused = false;
  }
}


