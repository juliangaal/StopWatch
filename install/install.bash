#!/bin/bash
git clone https://github.com/juliangaal/StopWatch
cd StopWatch
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. # default /usr/local on Mac/Linux
make && sudo make install