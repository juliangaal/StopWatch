/* 
 * File:   StopWatch.cpp
 * Author: Julian Gaal
 * From: https://github.com/juliangaal/StopWatch
 *
 * Created on 2018-29-06
 */


#ifndef STOP_WATCH_HPP
#define STOP_WATCH_HPP

#include <chrono>

using Clock = std::chrono::steady_clock;
using rep = std::chrono::milliseconds::rep;
using std::chrono::nanoseconds;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::minutes;
using std::chrono::hours;
using std::chrono::duration_cast;

class StopWatch {
 public:
  StopWatch();
  StopWatch(const StopWatch &);
  ~StopWatch() = default;

  /**
  * Assignment operator
  * @param rhs other stopwatch
  * @return changed Stopwatch
  */
  StopWatch &operator=(const StopWatch &rhs);

  /**
  * Calculates elapsed nanoseconds
  * @return Elapsed nanoseconds
  */
  rep ElapsedNs() const;

  /**
  * Calculates elapsed microseconds
  * @return Elapsed microseconds
  */
  rep ElapsedUs() const;

  /**
  * Calculates elapsed milliseconds
  * @return Elapsed milliseconds
  */
  rep ElapsedMs() const;

  /**
  * Calculates elapsed seconds
  * @return Elapsed seconds
  */
  rep ElapsedSec() const;

  /**
  * Resets the start point
  */
  void Restart();

  /**
  * Resets the start point
  * @return the updated start point
  */
  Clock::time_point RestartPoint();

  /**
   * Pauses timer
   */
  void Pause();

  /**
   * Resumes timer
   */
  void Resume();

 private:
  Clock::time_point start;
  Clock::time_point pause;
  Clock::duration pauseDuration;
  bool paused;
};

#endif