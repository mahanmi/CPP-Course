#include <iostream>
#include <chrono>
using namespace std;

// ###################################################################
//                              Timer

std::chrono::high_resolution_clock::time_point start, stop;
void timer(chrono::high_resolution_clock::time_point &moment)
{
  moment = chrono::high_resolution_clock::now();
}
int Duration(chrono::high_resolution_clock::time_point start, chrono::high_resolution_clock::time_point stop)
{
  chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  return duration.count();
}
// ###################################################################
//                            Sort Array
void sortArray(int a[], int from, int to)
{
  bool changed = true;
  for (int i = to - 1; (i > 0) && (changed); i--)
  {
    changed = false;
    for (int j = (from - 1); j < i; j++)
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        changed = true;
      }
  }
}
// ###################################################################
//                          Print Array
void printArray(int array[], int n)
{
  cout << "{ ";
  for (int i = 0; i < n; i++)
  {
    cout << array[i] << " , ";
  }
  cout << "\b\b}" << endl;
}
// ###################################################################
//                             Swap
void swap(int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}
// ###################################################################
//                            sort 3 items
void sort(int &a, int &b, int &c)
{
  for (int i = 0; i < 2; i++)
  {
    if (a > b)
    {
      swap(a, b);
    }
    if (c < b)
    {
      swap(b, c);
    }
  }
}
// ###################################################################
//                         sort 3 items inverse
void sortInverse(int &a, int &b, int &c)
{
  for (int i = 0; i < 2; i++)
  {
    if (a < b)
    {
      swap(a, b);
    }
    if (c > b)
    {
      swap(b, c);
    }
  }
}
// ###################################################################
//                       Matrix Multiply
void matrixMultiply(long long int matrix1[][50], long long int matrix2[][50], int n)
{
  long long int result[50][50];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        result[i][j] += ((matrix1[i][k]) * (matrix2[k][j]));
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix1[i][j] = result[i][j];
    }
  }
}