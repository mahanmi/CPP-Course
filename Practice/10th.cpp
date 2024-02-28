#include <iostream>
using namespace std;

const int ROWS = 5000;
const int COLS = 5000;

void Print2DArray(int arr[][COLS], int r, int c)
{
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  int arr[ROWS][COLS] = {0};
  int r = ROWS;
  int c = COLS;

  cout << "2D Array" << endl;
  Print2DArray(arr, r, c);

  return 0;
}