#include <iostream>
using namespace std;
#define IoFast                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

int main()
{
  IoFast;
  int row, column, count;
  cin >> row >> column >> count;
  long long matrix[row][column];
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < count; i++)
  {
    int line, paintLine, color;
    cin >> line >> paintLine >> color;
    if (line == 1)
    {
      for (int j = 0; j < column; j++)
      {
        matrix[paintLine - 1][j] = color;
      }
    }
    else
    {
      for (int i = 0; i < row; i++)
      {
        matrix[i][paintLine - 1] = color;
      }
    }
  }
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
