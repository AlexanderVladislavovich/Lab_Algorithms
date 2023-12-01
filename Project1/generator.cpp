#include <random>
#include <iostream>


void Generator(int * arr, int end)
{
  for (int i = 0; i < end; i++)
  {
    arr[i] = rand() % 10000 - 5000;
  }
  std::cout << "\ngeneration complete" << std::endl;
}