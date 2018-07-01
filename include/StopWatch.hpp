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
#include <unordered_map>
#include <string>

using Clock = std::chrono::steady_clock;
using rep = std::chrono::milliseconds::rep;
using std::chrono::nanoseconds;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::minutes;
using std::chrono::hours;
using std::chrono::duration_cast;
using std::unordered_map;
using std::string;

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
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed nanoseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedNs(const string &timepointID = "start") const;

  /**
  * Calculates elapsed microseconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed microseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedUs(const string &timepointID = "start") const;

  /**
  * Calculates elapsed milliseconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed milliseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedMs(const string &timepointID = "start") const;

  /**
  * Calculates elapsed seconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed seconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedSec(const string &timepointID = "start") const;

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
   * Add timepoint
   * @param id name of timepoint for later use
   */
  void addTimePoint(const string &id);

  /**
   * Pauses timer
   */
  void Pause();

  /**
   * Resumes timer
   */
  void Resume();

 private:
  unordered_map<string, Clock::time_point> timepoints;
  Clock::duration pauseDuration;
  bool paused;
};

#endif