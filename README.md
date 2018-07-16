# StopWatch

[![Build Status](https://travis-ci.org/juliangaal/StopWatch.svg?branch=master)](https://travis-ci.org/juliangaal/StopWatch) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/86aa779facf347bbaed1062596dacf58)](https://www.codacy.com/app/juliangaal/StopWatch?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=juliangaal/StopWatch&amp;utm_campaign=Badge_Grade)

Timing utility, wraps C++11/14/17 [std::chrono](https://en.cppreference.com/w/cpp/header/chrono) in an easy to use StopWatch utility

Originally forked from [here](https://github.com/KjellKod/StopWatch)

## Installation
```bash
git clone https://github.com/juliangaal/StopWatch
cd StopWatch
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=your_install_prefix .. # default /usr/local on Mac/Linux
make
sudo make install
```
or use provided [install script](./install/install.bash) with default `CMAKE_INSTALL_PREFIX=/usr/local`

## Usage

#### Import
```cpp
#include <StopWatch/StopWatch.hpp>
```

#### Start StopWatch
```cpp
StopWatch s;
```

#### Restart StopWatch
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

#### Pause/Resume StopWatch
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

#### Get Elapsed Time
```cpp
int main(void) {
    StopWatch s;
    foo();
    cout << s.ElapsedNs()  << "\n";  // Elapsed Nanoseconds
    cout << s.ElapsedUs()  << "\n";  // Elapsed Microseconds
    cout << s.ElapsedMs()  << "\n";  // Elapsed Milliseconds
    cout << s.ElapsedSec() << "\n"; // Elapsed Seconds
    return 0;
}
```

or simply get summary:

```cpp
int main(void) {
    StopWatch s;
    foo();
    std::cout << s;
    return 0;
}
```
will output the time in format `seconds:milliseconds:nanoseconds`.
#### Use timepoints during running StopWatch. 
```cpp
int main(void) {
    StopWatch s;
    foo();
    s.addTimePoint("foo");
    bar();
    s.addTimePoint("bar");
    cout << s.ElapsedMs() << "\n";           // Elapsed time since start
    cout << s.ElapsedMsSince("foo") << "\n"; // Elapsed time since foo timepoint
    cout << s.ElapsedMsSince("bar") << "\n"; // Elapsed time since bar timepoint
    return 0;
}
```
If id of timepoint can't be found, elapsed time since start.

You can also run the provided Doxyfile to get generated docs.
