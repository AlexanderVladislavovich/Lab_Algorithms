//#include "../AVLtree/AVLtree.h"
//#include "../AVLtree/4MergeSort.cpp"
//#include <chrono>
//
//int main()
//{
//  //AVLtree a1;// a1.test();
//  //a1.InsertNode(10);
//  //
//  //a1.InsertNode(5);
//  //a1.InsertNode(3);
//  //a1.InsertNode(1);
//  //a1.InsertNode(18);
//  //a1.InsertNode(20);
//  //a1.InsertNode(30);
//  ////a1.InsertNode(5);
//  //a1.print();
//  auto starttime = chrono::system_clock::now();
//  int arr[10] = { 5,6,7,8,9,10,1,2,3,4 };
//  int arr2[10] = { 2,4,1,3,4,4,7,8,10,100 };
//
//  MergeSort(arr2, 1, 10,4);
//  //cout << "ddd";
//  //prt(arr);
//  //BubbleSort(arr,1,10);
//  //Merge(arr, 4, 6, 10);
//  cout << endl; 
//  for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
//  cout << endl;
//  for (int i = 0; i < 10; i++) cout << arr2[i] << ' ';
//  auto endtime = chrono::system_clock::now();
//  chrono::duration<double> Time = endtime - starttime;
//  cout << "time =" << Time.count() << endl;
//  return 0;
//}


#include "../Project1/tests.cpp"

int main()
{

  double time = testAVLtree(1000000000);
  cout << "\nSorting time: " << time << " sec" << endl;
  double time2 = test4MergeSort(1000000000);
  cout << "\nSorting time: " << time2 << " sec" << endl;
  return 0;
}