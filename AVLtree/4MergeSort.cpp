
#include <iostream>
using namespace std;


void Merge(int *arr, int i, int m ,int j)
{
  int* b = new int[j-i+1];
  int size = j - i + 1;
  int i1 = i - 1;int  i2 = m;
  int iter = 0;
  while (i1 + i2 < j + m )
  {
    
    if ((i1 < m && i2 < j && arr[i1] <= arr[i2]) || (i2 == j ))
    {
      b[i1 + i2 - i - m + 1] = arr[i1];
      
      i1++; iter++;
    }
    else { b[i1 + i2 - i - m + 1] = arr[i2]; i2++; iter++; }
  }
  for (int index = i - 1; index < j; index++)
  {
    arr[index ] = b[index - i + 1];
  }
  
  delete[] b;
}



void BubbleSort(int* arr, int i, int j)
{
  if (i == j) return;
  int start = i - 1; int end = j -1 ;
  for (int ind1 = start; ind1 < end ; ind1++)
  {
    for (int ind2 = start; ind2 < end ; ind2++)
    {
      if (arr[ind2] > arr[ind2 + 1])
      {
        int tmp = arr[ind2 + 1];
        arr[ind2 + 1] = arr[ind2];
        arr[ind2] = tmp;
      }
    }
  }
}

void MergeSort(int *arr, int i, int j, int k)
{
  if (j - i + 1 < k) BubbleSort(arr, i, j);
  else
  {
    int step = (j - i + 1) / k;
    for (int num = 0; num <= k - 1; num++)
    {
      if (num < k - 1)
      {
        MergeSort(arr, i + step * num , i + step * (num + 1) - 1 , k);
      }
      else MergeSort(arr, i + (k - 1) * step, j , k);
    }
    for (int num = 0; num <= k - 2; num++)
    {
      if (num < k - 2)
      {
        Merge(arr,i , i + step * (num + 1) - 1 , i + step * (num + 2) - 1); //
      }
      else Merge(arr, i , i + (k - 1) * step - 1 , j );
    }  
  }
}

