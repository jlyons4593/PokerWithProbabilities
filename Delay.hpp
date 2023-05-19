#ifndef DELAY_HPP
#define DELAY_HPP

#include <chrono>
#include <thread>


extern void delay(int milliseconds) {
  auto start_time = std::chrono::steady_clock::now();
  while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() < milliseconds) {
    // Do nothing, just wait for the time to pass
  }
}
#endif // DELAY_HPP