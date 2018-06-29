//
// Created by Julian on 29.06.18.
//
#include <iostream>
#include "../include/StopWatch.hpp"

int main(void) {
  StopWatch s;
  long long int t = 100000000000;
  double i = 0.0;
  while (i < t) {
    i += 100000;
  }
  std::cout << s.ElapsedNs() << "ns";
}

