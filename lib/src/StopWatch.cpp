/* 
 * File:   StopWatch.cpp
 * Author: Julian Gaal
 * From: https://github.com/juliangaal/StopWatch
 * 
 * Created on 2018-29-06
 */
#include "StopWatch.hpp"

using std::pair;

StopWatch::StopWatch() : pauseDuration(0),
                         paused(false) {
  timepoints["start"] = Clock::now();
  static_assert(Clock::is_steady, "Serious OS/C++ library issues. Steady Clock is not steady");
}

StopWatch::StopWatch(const StopWatch &other) : pauseDuration(0),
                                               paused(false) {
  timepoints.at("start") = other.timepoints.at("start");
}

StopWatch &StopWatch::operator=(const StopWatch &rhs) {
  timepoints.at("start") = rhs.timepoints.at("start");
  return *this;
}

rep StopWatch::ElapsedNs() const {
    return duration_cast<nanoseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedUs() const {
    return duration_cast<microseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedMs() const {
    return duration_cast<milliseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedSec() const {
    return duration_cast<seconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedNsSince(const string &timepointID) const {
  if (timepoints.find(timepointID) != end(timepoints))
    return duration_cast<nanoseconds>(Clock::now() - timepoints.at(timepointID) - pauseDuration).count();
  else
    return duration_cast<nanoseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedUsSince(const string &timepointID) const {
  if (timepoints.find(timepointID) != end(timepoints))
    return duration_cast<microseconds>(Clock::now() - timepoints.at(timepointID) - pauseDuration).count();
  else
    return duration_cast<microseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedMsSince(const string &timepointID) const {
  if (timepoints.find(timepointID) != end(timepoints))
    return duration_cast<milliseconds>(Clock::now() - timepoints.at(timepointID) - pauseDuration).count();
  else
    return duration_cast<milliseconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

rep StopWatch::ElapsedSecSince(const string &timepointID) const {
  if (timepoints.find(timepointID) != end(timepoints))
    return duration_cast<seconds>(Clock::now() - timepoints.at(timepointID) - pauseDuration).count();
  else
    return duration_cast<seconds>(Clock::now() - timepoints.at("start") - pauseDuration).count();
}

void StopWatch::Restart() {
  timepoints.at("start") = Clock::now();
}

Clock::time_point StopWatch::RestartPoint() {
  Restart();
  return timepoints.at("start");
}

void StopWatch::Pause() {
  if (!paused) {
    if (timepoints.find("pause") != end(timepoints)) {
      timepoints.at("pause") = Clock::now();
      paused = true;
    } else {
      timepoints["pause"] = Clock::now();
      paused = true;
    }
  }
}

void StopWatch::Resume() {
  if (paused) {
    pauseDuration += (Clock::now() - timepoints.at("pause"));
    paused = false;
  }
}

void StopWatch::addTimePoint(const string &id) {
  if (timepoints.find(id) != end(timepoints)) {
    timepoints.at(id) = Clock::now();
  } else {
    timepoints.insert(pair<string, Clock::time_point>(id, Clock::now()));
  }
}
