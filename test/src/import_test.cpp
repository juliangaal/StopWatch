//
// Created by Julian on 30.06.18.
// Only exists for travis
//

#include <StopWatch/StopWatch.hpp>
#include <iostream>

int main(void) {
  StopWatch s;
  std::cout << s.ElapsedMs() << "\n";
  return 0;
}