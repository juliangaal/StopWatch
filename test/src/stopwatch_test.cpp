//
// Created by Julian on 29.06.18.
//
#include <iostream>
#include <thread>
#include <cassert>
#include "../../lib/include/StopWatch.hpp"

using std::string;
using std::this_thread::sleep_for;
using std::chrono::nanoseconds;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::minutes;
using std::chrono::hours;
using std::chrono::duration_cast;

template<typename TimingFunction, typename ResultFunction>
void RunAndTime(string title, rep goal, TimingFunction timingFunc, ResultFunction resultFunc) {
  std::cout << title;
  StopWatch s;
  timingFunc();
  assert(goal == resultFunc(s));
  std::cout << " -> Success" << "\n";
}

template<typename T>
bool inRange(const T lower_bound, const T result, const T upper_bound) {
  return result > lower_bound && result < upper_bound;
}

int main(void) {
  StopWatch s;
  {
    const string title = "Run for 1s";
    constexpr rep goal = 1.0;
    auto timing_func = []() { return sleep_for(seconds(1)); };
    auto result_func = [](const StopWatch &s) { return s.ElapsedSec(); };
    RunAndTime(title, goal, timing_func, result_func);
  }

  {
    const string title = "Run for 1s, wait for 1";
    constexpr rep goal = 1.0;
    auto timing_func = []() { return sleep_for(seconds(1)); };
    auto result_func = [](StopWatch &s) {
      s.Pause();
      std::this_thread::sleep_for(seconds(1));
      s.Resume();
      return s.ElapsedSec();
    };
    RunAndTime(title, goal, timing_func, result_func);
  }

  {
    const string title = "Run for 1s, wait for 1, set timepoint";
    constexpr rep goal = 1.0;
    auto timing_func = []() { return sleep_for(seconds(1)); };
    auto result_func = [](StopWatch &s) {
      s.addTimePoint("custom");
      std::this_thread::sleep_for(seconds(1));
      return s.ElapsedSecSince("custom");
    };
    RunAndTime(title, goal, timing_func, result_func);
  }

  {
    const string title = "Run for 1000ms";
    constexpr rep goal = 1000.0;
    constexpr rep upper_limit = 1500.0;
    auto timing_func = []() { return sleep_for(milliseconds(1000)); };
    auto result_func = [&](StopWatch &s) {
      auto result = s.ElapsedMs();
      if (inRange(goal, result, upper_limit))
        return goal;
      else
        return goal * 2;
    };
    RunAndTime(title, goal, timing_func, result_func);
  }

  {
    const string title = "Run for 1000000ns";
    constexpr rep goal = 1000000.0;
    constexpr rep upper_limit = 1500000.0;

    auto timing_func = []() { return sleep_for(nanoseconds(1000000)); };
    auto result_func = [&](StopWatch &s) {
      auto result = s.ElapsedNs();
      if (inRange(goal, result, upper_limit))
        return goal;
      else
        return goal * 2;
    };
    RunAndTime(title, goal, timing_func, result_func);
  }

  std::cout << s;

  return EXIT_SUCCESS;
}
