#include "../AVLtree/AVLtree.h"
#include "../AVLtree/4MergeSort.cpp"
#include "generator.cpp"
#include "timer.cpp"


double testAVLtree(int size)
{
  int* arr = new int[size];
  Generator(arr, size);
  AVLtree a;

  Timer t;
  a.sort(arr, size);

  double time = t.check().count();
  delete[] arr;
  return time;
}

double test4MergeSort(int size)
{
  int* arr = new int[size];
  Generator(arr, size);

  Timer t;
  MergeSort(arr, 1, size, 4);

  double time = t.check().count();
  delete[] arr;
  return time;
}
