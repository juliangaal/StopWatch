# StopWatch

[![Build Status](https://travis-ci.org/juliangaal/StopWatch.svg?branch=master)](https://travis-ci.org/juliangaal/StopWatch)

Timing utility, wraps C++11/14/17 [std::chrono](https://en.cppreference.com/w/cpp/header/chrono) in an easy to use StopWatch utility

Originally forked from [here](https://github.com/KjellKod/StopWatch)

## Usage

Import
```cpp
#include <StopWatch>
```

Start StopWatch
```cpp
int main(void) {
    StopWatch s;
    return 0;
}
```

Restart StopWatch
```cpp
int main(void) {
    StopWatch s;
    foo();
    s.Restart();
    bar();
    cout << s.RestartPoint(); // restarts and returns new start point
    return 0;
}
```

Pause/Resume StopWatch
```cpp
int main(void) {
    StopWatch s;
    foo();
    s.Pause();
    bar();
    s.Resume();
    foobar();
    return 0;
}
```

Get Elapsed Time
```cpp
int main(void) {
    StopWatch s;
    foo();
    cout << s.ElapsedNs();  // Elapsed Nanoseconds
    cout << s.ElapsedUs();  // Elapsed Microseconds
    cout << s.ElapsedMs();  // Elapsed Milliseconds
    cout << s.ElapsedSec(); // Elapsed Seconds
    return 0;
}
```

Use timepoints during running StopWatch. 
```cpp
int main(void) {
    StopWatch s;
    foo();
    s.addTimePoint("foo");
    bar();
    s.addTimePoint("bar");
    cout << s.ElapsedMs();      // Elapsed time since start
    cout << s.ElapsedMs("foo"); // Elapsed time since foo timepoint
    cout << s.ElapsedMs("bar"); // Elapsed time since bar timepoint
    return 0;
}
```
If id of timepoint can't be found, elapsed time since start.

You can also run the provided Doxyfile to get generated docs.
