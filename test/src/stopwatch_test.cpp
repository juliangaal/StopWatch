//
// Created by Julian on 29.06.18.
//
#include <iostream>
#include <thread>
#include <cassert>
#include <StopWatch/StopWatch.hpp>

using std::string;
using std::this_thread::sleep_for;

template<typename TimingFunction, typename ResultFunction>
void RunAndTime(string title, double goal, TimingFunction timingFunc, ResultFunction resultFunc) {
  StopWatch s;
  timingFunc();
  assert(goal == resultFunc(s));
  std::cout << title << " -> Success" << "\n";
}

int main(void) {
  RunAndTime("Run for 1s", 1, []() { sleep_for(seconds(1)); }, [](StopWatch &s) { return s.ElapsedSec(); });

  RunAndTime("Run for 1s, wait for 1", 1,
             []() { sleep_for(seconds(1)); },
             [](StopWatch &s) {
               s.Pause();
               std::this_thread::sleep_for(seconds(1));
               s.Resume();
               return s.ElapsedSec();
             });

  RunAndTime("Run for 1s, wait for 1, set timepoint", 1,
             []() { sleep_for(seconds(1)); },
             [](StopWatch &s) {
               s.addTimePoint("custom");
               std::this_thread::sleep_for(seconds(1));
               return s.ElapsedSecSince("custom");
             });

  RunAndTime("Run for 1000ms", 1000,
             []() { sleep_for(milliseconds(1000)); },
             [](StopWatch &s) {
               auto result = s.ElapsedMs();
               if (result < 1500 && result >= 1000)
                 return 1000;
               else
                 return 999;
             });

  RunAndTime("Run for 1000000ns", 1000000,
             []() { sleep_for(nanoseconds(1000000)); },
             [](StopWatch &s) {
               auto result = s.ElapsedNs();
               if (result < 1500000 && result >= 1000000)
                 return 1000000;
               else
                 return 999999;
             });

  return EXIT_SUCCESS;
}
