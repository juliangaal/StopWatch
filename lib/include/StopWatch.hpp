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

class StopWatch {
 public:
  /// default constructor
  StopWatch();

  /// copy constructor
  StopWatch(const StopWatch &);

  /// default destructor
  ~StopWatch() = default;

  /**
  * Assignment operator
  * @param rhs other stopwatch
  * @return changed Stopwatch
  */
  StopWatch &operator=(const StopWatch &rhs);

  /**
   * Operator overloaded: pipes summary into ostream
   * @param os std::ostream
   * @param s StopWatch object
   * @return modified ostream
   */
  friend std::ostream &operator<<(std::ostream &os, const StopWatch &s);

  /**
  * Calculates elapsed nanoseconds
  * @return Elapsed nanoseconds since start
  */
  rep ElapsedNs() const;

  /**
  * Calculates elapsed microseconds
  * @return Elapsed microseconds since start
  */
  rep ElapsedUs() const;

  /**
  * Calculates elapsed milliseconds
  * @return Elapsed milliseconds since start
  */
  rep ElapsedMs() const;

  /**
  * Calculates elapsed seconds
  * @return Elapsed seconds since start
  */
  rep ElapsedSec() const;

  /**
  * Calculates elapsed nanoseconds
  * @return Elapsed nanoseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedNsSince(const std::string &timepointID = "start") const;

  /**
  * Calculates elapsed microseconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed microseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedUsSince(const std::string &timepointID = "start") const;

  /**
  * Calculates elapsed milliseconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed milliseconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedMsSince(const std::string &timepointID = "start") const;

  /**
  * Calculates elapsed seconds
  * @param timepointID (optional) id of timepoint to get elapsed time from
  * @return Elapsed seconds since timepoint. If timepoint doesn't exist: return time since start
  */
  rep ElapsedSecSince(const std::string &timepointID = "start") const;
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
  void addTimePoint(const std::string &id);

  /**
   * Pauses timer
   */
  void Pause();

  /**
   * Resumes timer
   */
  void Resume();

 private:
  /**
   * Saves timepoints with id and time_point
   */
  std::unordered_map<std::string, Clock::time_point> timepoints;

  /**
   * Saves total pause duration for subtracting from total runtime
   */
  Clock::duration pauseDuration;

  /**
   * If StopWatch is paused or not
   */
  bool paused;
};

#endif