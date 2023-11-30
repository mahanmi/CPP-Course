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