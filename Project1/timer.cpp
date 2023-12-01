
#include <chrono>


class Timer
{
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;

public:

  Timer()
  {
    start = std::chrono::high_resolution_clock::now();
  }
  std::chrono::duration<double>  check()
  {
     end = std::chrono::high_resolution_clock::now();
    return end - start;
  }

};